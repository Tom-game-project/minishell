#include "list.h"
#include "tom_parser.h"
//#include "test_tools.h"
#include <stdbool.h>
#include <unistd.h>

typedef enum e_anchor t_anchor;
enum e_anchor
{
	e_in_q,
	e_in_dq,
	e_outof_q
};

bool is_ifs(char c)
{
	return (
		c == '\t' || \
		c == '\n' || \
		c == ' '
	);
}

bool is_ope_char(char c)
{
	return (
		c == '<' || \
		c == '>' || \
		c == '|' || \
		c == '&'
	);
}

/// ```bash
/// ls -la &&(cat ) | "hello world"
/// ```
/// -> 
/// ```
/// 'ls' '-la' '&&' '(cat )' '|' '"hello world"'
/// ```
///
/// 演算子(operator)文字列が含まれる場合groupに追加する
/// ```
/// `<`, `>`, `|`, `||`, `&&`, `<<`, `>>`
/// ```
t_char_list *pre_lexer(t_char_list **clst)
{
	char c;
	t_anchor p;
	int depth;
	int idx;

	depth = 0;
	idx = 0;
	p = e_outof_q;
	while (1)
	{
		c = char_list_get_elem(*clst, idx);
		if (c == '\0')
			break;
		if (p == e_outof_q) // シングルクォーテーション中
		{
			// 何もないところにおける文字の区切り
			if (c == '\''){
				p = e_in_q;
			}
			else if (c == '"')
				p = e_in_dq;
			else if (c == '(')
			{
				depth += 1;
			}
			else if (c == ')')
			{
				depth -= 1;
				if (depth == 0)
				{
					return (char_list_cut(clst, idx));
				}
			}
			else if (depth == 0) // クォーテーションに入っていない
					     // かつ、カッコの内ではない
			{
				if (is_ifs(c) || is_ope_char(c))
				{
					if (idx == 0)
						return (char_list_cut(clst, idx));
					else 
						return (char_list_cut(clst, idx - 1));
				}
			}
		}
		else if (p == e_in_dq) // ダブルクォーテーション中
		{
			if (c == '"')
			{
				p = e_outof_q;
				if (depth == 0)
					return (char_list_cut(clst, idx));
			}
		}
		else if (p == e_in_q) // クォーテーション外
		{
			if (c == '\'')
			{
				p = e_outof_q;
				if (depth == 0)
					return (char_list_cut(clst, idx));
			}
		}
		idx += 1;
	}
	return (char_list_cut(clst, idx));
}

/// 意味ごとの分類
t_str_list *lexer(char *str)
{
	t_char_list *lst;
	char *s;
	t_char_list *head;

	lst = NULL;
	char_list_push_str(&lst, str);
	t_str_list *lexed;
	lexed = NULL;
	while (1)
	{
		head  = pre_lexer(&lst);
		if (head == NULL)
			break;
		s = char_list_to_str(head);
		char_list_clear(&head);
		str_list_push(&lexed, s);
	}
	ope_collector(&lexed);
	return (lexed);
}
