#include "list.h"
#include "tom_parser.h"
#include "private.h"
//#include "test_tools.h"
#include <stdbool.h>
#include <unistd.h>

/// 妥協案
///
/// bool
/// - true -> returnする
/// - false -> returnしない
static bool	cur_out_of_quotation(t_cur_anchor *s)
{
	if (s->c == '\'')
		*s -> anchor = e_in_q;
	else if (s->c == '"')
		*s->anchor = e_in_dq;
	else if (s->c == '(')
		*s->depth += 1;
	else if (s->c == ')')
	{
		*s->depth -= 1;
		if (*s->depth == 0)
		{
			*s->cut_list = char_list_cut(s->clst, s->idx);
			return (true);
		}
	}
	else if (*s->depth == 0)
	{
		if (is_ifs(s->c) || is_ope_char(s->c))
		{
			if (s->idx == 0)
				*s->cut_list = char_list_cut(s->clst, s->idx);
			else
				*s->cut_list = char_list_cut(s->clst, s->idx - 1);
			return (true);
		}
	}
	return (false);
}

static bool	cur_loop(t_cur_anchor *s)
{
	if (*s->anchor == e_outof_q)
	{
		if (cur_out_of_quotation(s))
			return (true);
	}
	else if (*s->anchor == e_in_dq)
	{
		if (s->c == '"')
		{
			*s->anchor = e_outof_q;
			if (*s->depth == 0)
			{
				*s->cut_list = char_list_cut(s->clst, s->idx);
				return (true);
			}
		}
	}
	else if (*s->anchor == e_in_q)
	{
		if (s->c == '\'')
		{
			*s->anchor = e_outof_q;
			if (*s->depth == 0)
			{
				*s->cut_list = char_list_cut(s->clst, s->idx);
				return (true);
			}
		}
	}
	return (false);
}

/// 文字リストの先頭から一つ要素を取得
static bool char_iter(t_char_list **clst, int idx, char *c)
{
	*c = char_list_get_elem(*clst, idx);
	return (*c != '\0');
}

/// ```bash
/// ls -la &&(cat ) | "hello world"
/// ```
/// -ls -la &&(cat ) | "hello world"> 
/// ```
/// 'ls' '-la' '&&' '(cat )' '|' '"hello world"'
/// ```
///
/// 演算子(operator)文字列が含まれる場合groupに追加する
/// ```
/// `<`, `>`, `|`, `||`, `&&`, `<<`, `>>`
/// ```
static t_char_list *pre_lexer(t_char_list **clst)
{
	t_anchor p;
	int depth;
	int idx;
	t_char_list *cut_list;
	char c;

	depth = 0;
	idx = 0;
	p = e_outof_q;
	cut_list = NULL;
	while (char_iter(clst, idx, &c))
	{
		if (cur_loop(&(t_cur_anchor){\
			c, &p, &depth, idx, clst, &cut_list}))
			return (cut_list);
		idx += 1;
	}
	return (char_list_cut(clst, idx));
}

/// 意味ごとの分類
t_str_list	*lexer(char *str)
{
	t_char_list	*lst;
	char		*s;
	t_char_list	*head;
	t_str_list	*lexed;

	lst = NULL;
	char_list_push_str(&lst, str);
	lexed = NULL;
	while (1)
	{
		head = pre_lexer(&lst);
		if (head == NULL)
			break ;
		s = char_list_to_str(head);
		char_list_clear(&head);
		str_list_push(&lexed, s);
	}
	ope_collector(&lexed);
	return (lexed);
}
