#include "parser.h"
#include "dict.h"
#include "test_tools.h"
#include "exec.h"
#include "ast_checker.h"

/// astを読み込み、exit_statusを返却する
int	exec_ast(t_ast *ast, t_str_dict **env_dict, t_syntax_result	result)
{

	debug_dprintf(STDERR_FILENO, "ORIGIN PID (%d)\n", debug_getpid());
	if (ast == NULL)
	{
		return (1);
	}
	if (print_checker_result(result))
	{
		print_ast(ast, 0);
		return (exec(ast, env_dict));
	}
	else
	{
		return (1);
	}
	return (0);
}
