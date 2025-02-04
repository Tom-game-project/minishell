#include "libft.h"
#include "parser.h"

t_ast   *parser(char *input)
{
	t_ast		*ast;

    ast = allocation_ast();
	separate_and_store_control_operators(ast, input);
	if (ast != NULL)
		return (ast);
	// ast = separate_and_store_redirect_operators(ast, &input);
	// if (ast != NULL)
	// 	return (ast);
	// ast = separate_and_store_cmd_args(ast, &input);
	// if (ast != NULL)
	// 	return (ast);
	return (NULL);
}
