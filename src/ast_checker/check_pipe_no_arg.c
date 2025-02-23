
# include "ast_checker.h"

t_syntax_result check_pipe_no_arg(t_ast *ast);

t_syntax_result ast_check_pipe_no_arg(t_ast *ast)
{
    t_syntax_result	check_result;

    if (ast == NULL)
        return (e_syntax_ok);
    check_result = check_pipe_no_arg(ast);
    if (check_result != e_syntax_ok)
        return (check_result);
    check_result = ast_checker(ast->left_ast);
    if (check_result != e_syntax_ok)
        return (check_result);
    check_result = ast_checker(ast->right_ast);
    return (check_result);
}

t_syntax_result check_pipe_no_arg(t_ast *ast)
{
    t_syntax_result result;

    result = e_syntax_ok;
    if (ast->ope == e_ope_pipe
        && (ast->left_ast == NULL || ast->right_ast == NULL))
        result = e_rdt_near_unexpected_token_pipe;
    return (result);
}