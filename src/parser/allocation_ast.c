# include "parser.h"
# include <stdlib.h>

t_ast  *allocation_ast(void)
{
	t_ast *ast;

	ast = (t_ast *)malloc(sizeof(t_ast));
	if (ast == NULL)
		exit(EXIT_FAILURE);
	ast->left_ast = NULL;
	ast->right_ast = NULL;
	ast->ope = e_ope_none;
	ast->arg = NULL;
	return (ast);
}
