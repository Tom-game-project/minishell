#include "libft.h"
#include "parser.h"
#include <stdlib.h>

void	parser(t_ast *ast, char *input)
{
	if (input == NULL)
		return ;
	separate_and_store_control_operators(ast, &input);
	separate_and_store_redirect_operators(ast, &input);
	separate_and_store_cmd_args(ast, &input);
	ast->right_ast = allocation_ast();
	if (ast->right_ast != NULL)
		return ;
	parser(ast->right_ast, ast->cmd);
	return ;
}
