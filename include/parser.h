#ifndef PARSER_H
# define PARSER_H

# include <unistd.h>
# include <stdbool.h>

typedef enum    e_ctl_operator t_ctl_operator;

enum	e_ctl_operator
{
	e_ctlope_none,
	e_ctlope_and,// &&
	e_ctlope_or,// ||
};

typedef enum    e_rdt_operator t_rdt_operator;

enum    e_rdt_operator
{
	e_rdtope_none,
	e_rdtope_redirect_i,// <
	e_rdtope_redirect_o,// >
	e_rdtope_heredoc_i,// <<
	e_rdtope_heredoc_o,// >>
	e_rdtope_pipe// |
};

typedef struct s_ast t_ast;

struct  s_ast
{
	t_ast   	    *right_ast;
	t_ctl_operator  ctlope;
	t_rdt_operator	rdtope;
	char        	*cmd;
	char        	**argv;
};

//parser.c
t_ast   *parser(char *input);

//allocation_ast.c
t_ast  *allocation_ast(void);

//checker_is.c
bool is_string(char *element);
bool is_control_operators(char *element);
bool is_redirect_operators(char *element);

//find_chr.c
size_t	find_chr(char *input, char find);

//separate_and_store_cmd_args.c
t_ast   *separate_and_store_cmd_args(t_ast *ast, char **input);

//separate_and_store_ctl_ope.c
void	separate_and_store_control_operators(t_ast  *ast, char *input);

//separate_and_store_rdt_ope.c
void   separate_and_store_redirect_operators(t_ast  *ast, char *input);

//update_input.c
void	update_input(char **input, char *head_element);

#endif
