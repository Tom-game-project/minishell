#include "ast_checker.h"
#include "parser.h"

static t_syntax_result	syntax_check(t_ast	*ast);

t_syntax_result ast_checker(t_ast	*ast)
{
	t_syntax_result	check_result;

	if (ast == NULL)
        return (e_syntax_ok);
	check_result = syntax_check(ast);
    if (check_result != e_syntax_ok)
        return (check_result);
    check_result = ast_checker(ast->left_ast);
    if (check_result != e_syntax_ok)
        return (check_result);
    check_result = ast_checker(ast->right_ast);
    return (check_result);
}

static t_syntax_result	syntax_check(t_ast	*ast)
{
	t_syntax_result	check_result;

	check_result = check_ctl_no_element(ast);//隣り合うctlopeの確認
	if (check_result != e_syntax_ok)
		return (check_result);
	check_result = check_pipe_no_arg(ast);//pipeが左右に要素を持っているかの確認
	if (check_result != e_syntax_ok)
		return (check_result);
	check_result = check_rdt_no_arg(ast);//rdt文字が引数を持たないとき
	if (check_result != e_syntax_ok)
		return (check_result);
	check_result = check_rdt_no_element(ast);//隣り合うrdtopeの確認(引数にrdt文字を持つとき)
	if (check_result != e_syntax_ok)
		return (check_result);
	check_result = check_element(ast);
	if (check_result != e_syntax_ok)
		return (check_result);
	return (e_syntax_ok);
}
