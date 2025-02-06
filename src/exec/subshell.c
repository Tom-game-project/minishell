
#include "built_in.h"
#include "exec.h"
#include "parser.h"
#include "pipe.h"

int subshell(char *input, char *envp[])
{
	t_ast	*ast;
	int exit_status;

	ast = NULL;
	parser(&ast, input);
	if (checker_cmd(ast))
	{
		exit_status = exec(ast, envp);
		return (exit_status);
	}
	exit_status = subshell(ast->cmd, envp);
	return (exit_status);
}
