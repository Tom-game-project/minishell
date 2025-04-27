# include "ast_checker.h"
#include "list.h"
# include "parser.h"
#include <unistd.h>


t_syntax_result check_rdt_no_arg(t_ast *ast)
{
    if (is_enum_rdtope(ast->ope) && str_list_len(ast->arg) == 0)
            return (e_rdt_near_unexpected_token_newline);
    else
	    return (e_syntax_ok);
}
