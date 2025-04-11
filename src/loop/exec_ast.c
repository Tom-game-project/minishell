#include "parser.h"
#include "dict.h"
#include "test_tools.h"
#include "exec.h"
#include "ast_checker.h"

void	exec_ast(t_ast *ast, t_str_dict **env_dict, int *exit_status)
{
	t_syntax_result	result;

	debug_dprintf(STDERR_FILENO, "ORIGIN PID (%d)\n", debug_getpid());
	if (ast == NULL)
	{
		*exit_status = 1;
		return ;
	}
	result = ast_checker(ast);
	print_checker_result(result);
	if (result == e_no_input)
	{
		debug_dprintf(STDERR_FILENO, "no_input\n");
		clear_ast(&ast);
	}
	else if (print_checker_result(result))
	{
		print_ast(ast, 0);
		*exit_status = exec(ast, env_dict);
		clear_ast(&ast);
	}
}
