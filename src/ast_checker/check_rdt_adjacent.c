#include "ast_checker.h"
#include "parser.h"

bool    is_rdt_ope(t_operator ope);

t_syntax_result check_rdt_no_element(t_ast *ast)
{
    t_syntax_result result;

    result = e_syntax_ok;
    if (is_rdt_ope(ast->ope))
    {
        if (ast->left_ast == NULL || ast->right_ast == NULL)
            result = e_ctl_near_unexpected_token_and;
    }
    return (result);
}

bool    is_rdt_ope(t_operator ope)
{
    if (ope == e_ope_redirect_i)
        return (true);
    else if (ope == e_ope_redirect_o)
        return (true);
    else if (ope == e_ope_heredoc_i)
        return (true);
    else if (ope == e_ope_heredoc_o)
        return (true);
    else
        return (false);
}