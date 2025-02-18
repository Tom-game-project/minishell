# ifndef PARSER_H
#define PARSER_H
#include "list.h"
#include "dict.h"
# include <unistd.h>
# include <stdbool.h>

t_str_list *expand_string(char *str, t_str_dict *env_dicts);

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

enum e_parse_result {
	e_result_ok,
	e_result_paren_not_closed_err,
};

//parser.c
t_parse_result	parser(t_ast **ast, char *input);

//allocation_ast.c
t_ast  *allocation_ast(void);

//checker_is.c
bool is_string(char *element);
bool is_control_operators(char *element);
bool is_redirect_operators(char *element);
bool ft_isspace(char c);

//find_chr.c
int find_syntax(char *input);

//separate_and_store_cmd_args.c
void   separate_and_store_cmd_args(t_ast *ast, char **input);
char	*search_delimiter(char *input);

//separate_and_store_ctl_ope.c
t_str_list	*separate_and_store_control_operators(t_ast  *ast, char **input);

//separate_and_store_rdt_ope.c
t_str_list	*separate_and_store_redirect_operators(t_ast  *ast, char **input);

//update_input.c
void	update_input(char **input, char *head_element);

//trim_isspc.c
char *trim_isspc(char *str);

//checker_str.c
bool    checker_str_ctl(char *str);
bool    checker_str_rdt(char *str);
int    str_ctl_len(char *str);
int    str_rdt_len(char *str);

void clear_ast(t_ast **ast);

int syntax_checker(char *input);

# endif
