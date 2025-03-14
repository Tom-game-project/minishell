#include "parser.h"
#include "list.h"
#include <stdbool.h>
#include <stdlib.h>

bool syntax_checker(char *input)
{
    int            tmp;
    int            idx;

    idx = 0;
    while (*(input + idx) != '\0')
    {
        if (*(input + idx) == ')')
            return (false);
        tmp = find_syntax(input + idx);
        if (tmp < 0)
            return (false);
        else if (tmp > 0)
            idx += tmp;
        else
            idx++;
    }
    return (true);
}



typedef enum e_anchor t_anchor;
enum e_anchor
{
	e_in_q,
	e_in_dq,
	e_outof_q
};


/// ```bash
/// "("
/// '('
/// 
/// ```
/// おそらくsyntax checker関数は、閉じられていないカッコを検出したい
bool syntax_checker2(char *input)
{
	t_char_list *lst;
	t_anchor p;
	char c;
	int depth;

	lst = NULL;
	p =  e_outof_q;
	depth = 0;
	char_list_push_str(&lst ,input);
	while(char_list_len(lst) != 0)
	{
		c = char_list_pop(&lst, 0);
		if (p == e_outof_q) // シングルクォーテーション中
		{
			if (c == '\'')
				p = e_in_q;
			else if (c == '"')
				p = e_in_dq;
			else if (c == '(')
				depth += 1;
			else if (c == ')')
				depth -= 1;
			else{}
		}
		else if (p == e_in_dq) // ダブルクォーテーション中
		{
			if (c == '"')
				p = e_outof_q;
			else{}
		}
		else if (p == e_in_q) // クォーテーション外
		{
			if (c == '\'')
				p = e_outof_q;
			else{}
		}
		else {} // unreachable
	}
	char_list_clear(&lst);
	return (depth == 0);
}
