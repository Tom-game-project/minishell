#ifndef PARSER_H
# define PARSER_H

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

typedef enum    e_operator t_operator;

enum    e_operator
{
	e_ope_none,
	e_ope_redirect_i, // <
	e_ope_redirect_o, // >
	e_ope_heredoc_i,  // <<
	e_ope_heredoc_o,  // >>
	e_ope_and,        // &&
	e_ope_or          // || 
};

typedef struct s_ast t_ast;

struct  s_ast
{
	t_ast       *left_ast;
	t_ast       *right_ast;
	t_operator  ope;
	char        *cmd;
	char        **argv;
};

t_ast  *parse_recursive(t_ast *ast, char *input);
t_ast  *allocation_ast(void);
void    check_operator(t_ast *ast, char *input);

#endif