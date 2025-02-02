#include "parser.h"

t_ast  *allocation_ast(void);
void	parce_cmd_args(t_ast *ast, char *element, char    **input);
void	parce_control_operators(t_ast *ast, char *element, char    **input);
void	parce_redirection_operators(t_ast *ast, char *element, char    **input);

t_ast   *parser(char *input)
{
	t_ast		*ast;

    ast = allocation_ast();
	ast = parse_recursive(ast, &input);
	return (ast);
}

t_ast  *allocation_ast(void)
{
	t_ast *ast;

	ast = (t_ast *)malloc(sizeof(t_ast));
	if (ast == NULL)
		exit(1);
	return (ast);
}

t_ast   *parse_recursive(t_ast *ast, char    **input)
{   
	char	*element;

	if (input == NULL)
		return ;
	element = search_operater(&input)
	if (ft_strncmp(element, "&&", 2) == 0 || ft_strncmp(element, "||", 2) == 0
		|| ft_strncmp(element, "(", 1) == 0)
		parce_control_operators(ast, element, &input);
	else if (ft_strncmp(element, "<<", 2) == 0 || ft_strncmp(element, ">>", 2) == 0
		|| ft_strncmp(element, "<", 1) == 0 || ft_strncmp(element, ">", 1) == 0
		|| ft_strncmp(element, "|", 1) == 0)
		parce_redirection_operators(ast, element &input);
	else
		parce_cmd_args(ast, element &input);
	ast->left = allocation_ast();
	parse_recursive(ast->left, &input);
	return ;
}

void	parce_cmd_args(t_ast *ast, char *element, char    **input)
{
	//格納処理
	ast->right = allocation_ast();
	parse_recursive(ast->right, &input);
	return ;
}

void	parce_control_operators(t_ast *ast, char *element, char    **input)
{
	//格納処理
	ast->left = allocation_ast();
	parse_recursive(ast->left, &input);
	return ;
}

void	parce_redirection_operators(t_ast *ast, char *element, char    **input)
{
	//格納処理
}
