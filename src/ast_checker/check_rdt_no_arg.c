# include "ast_checker.h"
# include "parser.h"

t_syntax_result check_rdt_no_arg(t_ast *ast)
{
    t_syntax_result result;

    result = e_syntax_ok;
    if (ast->ope != e_ope_pipe && is_enum_rdtope(ast->ope)
        && ast->right_ast != NULL && ast->right_ast->ope == e_ope_pipe
        && ast->right_ast->left_ast == NULL)
            result = e_syntax_ok;
    else if (ast->ope == e_ope_pipe
        && (ast->right_ast == NULL))
        result = e_rdt_near_unexpected_token_pipe;
    else if (ast->ope != e_ope_pipe && is_enum_rdtope(ast->ope))
    {
        if (ast->arg->ptr.str == NULL)
            result = e_rdt_near_unexpected_token_newline;
    }
    return (result);
}