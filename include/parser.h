#ifndef PARSER_H
# define PARSER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

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

char	*search_operater(char **input);
void	update_input(char **input, char *head_element);
size_t	find_chr(char *input, char find);


#endif