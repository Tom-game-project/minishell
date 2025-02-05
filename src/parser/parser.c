#include "libft.h"
#include "parser.h"

#include <stdio.h>
t_ast   *parser(char *input)
{
	t_ast		*ast;

    ast = allocation_ast();
	if (ast != NULL)
		return (ast);
	separate_and_store_control_operators(ast, &input);
	separate_and_store_redirect_operators(ast, &input);
	separate_and_store_cmd_args(ast, &input);
	        printf("%s\n", ast->cmd);
    // if (ast->cmd != NULL)   
        printf("%s\n", ast->right_ast->cmd);
	return (ast);
}
