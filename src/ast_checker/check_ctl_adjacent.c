#include "ast_checker.h"
#include "parser.h"
#include <unistd.h>

t_syntax_result check_ctl_no_element(t_ast *ast)
{
    t_syntax_result result;

    result = e_syntax_ok;
    if (ast->ope == e_ope_and)
    {
        if (ast->left_ast == NULL || ast->right_ast == NULL)
            result = e_ctl_near_unexpected_token_and;
    }
    else if (ast->ope == e_ope_or)
    {
        if (ast->left_ast == NULL || ast->right_ast == NULL)
            result = e_ctl_near_unexpected_token_or;
    }
    return (result);
}