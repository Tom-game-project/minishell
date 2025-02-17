#include "list.h"
#include "parser.h"
#include <stdlib.h>

static void free_ast(t_ast *ast);

void clear_ast(t_ast *ast)
{
    if (ast == NULL)
        return ;
    if (ast->left_ast != NULL)
        clear_ast(ast->left_ast);
    if (ast->right_ast != NULL)
        clear_ast(ast->right_ast);
    free_ast(ast);
}

static void free_ast(t_ast *ast)
{
	ast->ope = e_ope_none;
	str_list_clear(&ast->arg, free);
    free(ast->left_ast);
	free(ast->right_ast);
}