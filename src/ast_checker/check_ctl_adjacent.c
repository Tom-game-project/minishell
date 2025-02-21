#include "ast_checker.h"
#include "parser.h"

t_syntax_result check_ctl_adjacent(t_ast *ast)
{
    t_syntax_result result;

    result = e_syntax_ok;
    if (ast->ope == e_ope_and || ast->ope == e_ope_or)
    {
        if (ast->ope == e_ope_and)
            result = e_ctl_near_unexpected_token_and;
        else if (ast->ope == e_ope_or)
            result = e_ctl_near_unexpected_token_or;
    }
    return (result);
}