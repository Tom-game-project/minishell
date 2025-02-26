#include "ast_checker.h"
#include "parser.h"

t_syntax_result check_rdt_no_element(t_ast *ast)
{
    t_syntax_result result;

    result = e_syntax_ok;
    if (is_enum_rdtope(ast->ope))
    {
        if (is_redirect_operators(ast->arg->ptr.str))
            result = e_rdt_near_unexpected_token_rdt;
    }
    return (result);
}
