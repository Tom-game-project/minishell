# include "ast_checker.h"
#include "parser.h"

static bool is_enum_rdtope(t_operator ope);

t_syntax_result check_rdt_no_arg(t_ast *ast)
{
    t_syntax_result result;

    result = e_syntax_ok;
    if (ast->ope == e_ope_pipe 
        && (ast->left_ast == NULL || ast->right_ast == NULL))
        result = e_rdt_near_unexpected_token_pipe;
    else if (ast->ope != e_ope_pipe && is_enum_rdtope(ast->ope))
    {
        if (ast->arg->str == NULL)
            result = e_rdt_near_unexpected_token_newline;
    }
    return (result);
}

static bool is_enum_rdtope(t_operator ope)
{
    if (ope == e_ope_pipe)
        return (true);
    else if (ope == e_ope_redirect_i)
        return (true);
    else if (ope == e_ope_redirect_o)
        return (true);
    else if (ope == e_ope_heredoc_i)
        return (true);
    else if (ope == e_ope_heredoc_o)
        return (true);
    return (false);
}