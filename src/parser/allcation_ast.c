# include "parser.h"
# include <stdlib.h>

t_ast  *allocation_ast(void)
{
	t_ast *ast;

	ast = (t_ast *)malloc(sizeof(t_ast));
	if (ast == NULL)
		exit(EXIT_FAILURE);
	return (ast);
}
