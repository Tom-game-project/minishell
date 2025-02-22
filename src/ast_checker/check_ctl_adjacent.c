#include "ast_checker.h"
#include "parser.h"

t_syntax_result check_ctl_adjacent(t_ast *ast);

t_syntax_result ast_check_ctl_adjacent(t_ast *ast)
{
    t_syntax_result	check_result;

    if (ast == NULL)
        return (e_syntax_ok);
    check_result = check_ctl_adjacent(ast);
    if (check_result != e_syntax_ok)
        return (check_result);
    check_result = ast_check_ctl_adjacent(ast->left_ast);
    if (check_result != e_syntax_ok)
        return (check_result);
    check_result = ast_check_ctl_adjacent(ast->right_ast);
    return (check_result);
}

t_syntax_result check_ctl_adjacent(t_ast *ast)
{
    t_syntax_result result;

    result = e_syntax_ok;
    if (ast->ope == e_ope_and || ast->ope == e_ope_or)
    {
        if (ast->left_ast != NULL && ast->left_ast->ope == e_ope_and)
            result = e_ctl_near_unexpected_token_and;
        else if (ast->left_ast != NULL && ast->left_ast->ope == e_ope_or)
            result = e_ctl_near_unexpected_token_or;
        if (ast->right_ast != NULL && ast->right_ast->ope == e_ope_and)
            result = e_ctl_near_unexpected_token_and;
        else if (ast->right_ast != NULL && ast->right_ast->ope == e_ope_or)
            result = e_ctl_near_unexpected_token_or;    
    }
    return (result);
}