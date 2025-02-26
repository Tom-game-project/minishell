#include "ast_checker.h"
#include "parser.h"

t_syntax_result	check_adjacent_strings(t_ast *ast)
{
    t_syntax_result	result;

	result = e_syntax_ok;
	if (ast->ope == e_ope_paren)
    {
        if (ast->right_ast != NULL)
        	result = e_syntax_near_unexpected_token_string;
    }
    if (ast->arg != NULL)
    {
        if (ast->right_ast->ope == e_ope_paren)
        	result = e_syntax_near_unexpected_token_string;
    }
	return (result);
}
