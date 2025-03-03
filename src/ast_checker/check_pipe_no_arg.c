
# include "ast_checker.h"

t_syntax_result check_pipe_no_arg(t_ast *ast)
{
    t_syntax_result result;

    result = e_syntax_ok;
    if (ast->ope == e_ope_pipe
        && (ast->left_ast == NULL || ast->right_ast == NULL))
        result = e_rdt_near_unexpected_token_pipe;
    return (result);
}