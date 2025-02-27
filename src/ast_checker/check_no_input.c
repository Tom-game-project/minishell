
#include "parser.h"
#include "ast_checker.h"
#include <stdio.h>

t_syntax_result check_no_input(t_ast *ast)
{
    t_syntax_result result;

    result = e_syntax_ok;
    if (ast->arg == NULL
        && ast->ope == e_ope_none
        && ast->left_ast == NULL
        && ast->right_ast == NULL)
        result = e_no_input;
    return (result);
}