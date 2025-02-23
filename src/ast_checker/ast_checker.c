#include "ast_checker.h"
#include "parser.h"

static t_syntax_result	syntax_check(t_ast	*ast);

t_syntax_result ast_checker(t_ast	*ast)
{
	t_syntax_result	check_result;

	check_result = syntax_check(ast);
	return (check_result);
}

static t_syntax_result	syntax_check(t_ast	*ast)
{
	t_syntax_result	check_result;

	check_result = ast_check_ctl_adjacent(ast);//隣り合うctlopeの確認
	if (check_result != e_syntax_ok)
		return (check_result);
	check_result = ast_check_pipe_no_arg(ast);//pipeが左右に要素を持っているかの確認
	if (check_result != e_syntax_ok)
		return (check_result);
	check_result = ast_check_rdt_no_arg(ast);//隣り合うrdtopeの確認
	if (check_result != e_syntax_ok)
		return (check_result);
	return (e_syntax_ok);
}
