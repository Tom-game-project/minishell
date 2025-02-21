# include "ast_checker.h"
#include "parser.h"

t_syntax_result check_rdt_no_arg(t_ast *ast)
{
    t_syntax_result result;

    result = e_syntax_ok;
    if (ast->ope == e_ope_pipe 
        && (ast->left_ast == NULL || ast->right_ast == NULL))
        result = e_rdt_near_unexpected_token_pipe;
    if (ast->ope == e_ope_heredoc_i && )
    return (result);
}