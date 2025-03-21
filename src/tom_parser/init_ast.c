#include "tom_parser.h"
#include <stdlib.h>

/// 
t_ast *init_ast()
{
	t_ast *ast;

	ast = (t_ast *)malloc(sizeof(t_ast));
	ast->arg = NULL;
	ast->left_ast = NULL;
	ast->right_ast = NULL;
	ast->ope = e_ope_none;
	return (ast);
}

