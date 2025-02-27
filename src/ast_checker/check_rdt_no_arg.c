# include "ast_checker.h"
# include "parser.h"
#include <unistd.h>


t_syntax_result check_rdt_no_arg(t_ast *ast)
{
    t_syntax_result result;

    result = e_syntax_ok;
    if (is_enum_rdtope(ast->ope))
    {
        if (ast->arg->ptr.str == NULL)
            result = e_rdt_near_unexpected_token_newline;
    }
    return (result);
}
