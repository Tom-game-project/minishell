#include "parser.h"
#include "dict.h"
#include "test_tools.h"
#include "exec.h"
#include "ast_checker.h"

/// exec関数を読んだら1を返します
int	exec_ast(t_ast *ast, t_str_dict **env_dict, int *exit_status)
{
	t_syntax_result	result;

	debug_dprintf(STDERR_FILENO, "ORIGIN PID (%d)\n", debug_getpid());
	if (ast == NULL)
	{
		*exit_status = 1;
		return (0);
	}
	result = ast_checker(ast);
	print_checker_result(result);
	if (result == e_no_input)
	{
		debug_dprintf(STDERR_FILENO, "no_input\n");
		return (0);
	}
	else if (print_checker_result(result))
	{
		print_ast(ast, 0);
		*exit_status = exec(ast, env_dict);
		return (1);
	}
	return (0);
}
