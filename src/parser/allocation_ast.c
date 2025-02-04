# include "parser.h"
# include <stdlib.h>

t_ast  *allocation_ast(void)
{
	t_ast *ast;

	ast = (t_ast *)malloc(sizeof(t_ast));
	if (ast == NULL)
		exit(EXIT_FAILURE);
	ast->right_ast = NULL;
	ast->ctlope = e_ctlope_none;
	ast->rdtope = e_rdtope_none;
	ast->cmd = NULL;
	ast->argv = NULL;
	return (ast);
}
