#ifndef TOM_PARSER_H
#define TOM_PARSER_H

#include "list.h"

typedef enum e_tom_parse_result t_tom_parse_result ;
enum e_tom_parse_result
{
	e_tom_result_ok,
	e_tom_result_paren_not_closed_err,
};

typedef enum    e_tom_operator t_tom_operator;

enum    e_tom_operator
{
	e_tom_ope_none,
	e_tom_ope_and,// &&
	e_tom_ope_or,// ||
	e_tom_ope_redirect_i,// <
	e_tom_ope_redirect_o,// >
	e_tom_ope_heredoc_i,// <<
	e_tom_ope_heredoc_o,// >>
	e_tom_ope_pipe,// |
	e_tom_ope_paren,// )
};

typedef struct s_tom_ast t_tom_ast;

struct  s_tom_ast
{
	t_tom_ast   	    *left_ast;
	t_tom_ast   	    *right_ast;
	t_tom_operator 		ope;
	t_str_list		*arg;
};

t_char_list *pre_lexer(t_char_list **clst);

int search_string_pattern_replace(t_str_list **lst, t_str_list *pattern);

int ope_collector(t_str_list **lexed);

t_str_list *
lexer(char *str);

t_tom_parse_result	tom_parser_lexed(t_tom_ast **ast, t_str_list *input);

t_tom_ast *init_ast();

#endif
