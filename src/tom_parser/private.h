#ifndef PRIVATE_H
#define PRIVATE_H

#include "list.h"

typedef enum    e_operator t_operator;

enum    e_operator
{
	e_ope_none,
	e_ope_and,// &&
	e_ope_or,// ||
	e_ope_redirect_i,// <
	e_ope_redirect_o,// >
	e_ope_heredoc_i,// <<
	e_ope_heredoc_o,// >>
	e_ope_pipe,// |
	e_ope_paren,// )
};

typedef struct s_ast t_ast;

struct  s_ast
{
	t_ast   	    *left_ast;
	t_ast   	    *right_ast;
	t_operator 		ope;
	t_str_list		*arg;
};

typedef enum e_parse_result t_parse_result ;

enum e_parse_result
{
	e_result_ok,
	e_result_paren_not_closed_err,
};

#endif
