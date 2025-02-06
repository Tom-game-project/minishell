
#include "built_in.h"
#include "exec.h"
#include "parser.h"
#include "pipe.h"
#include <stdbool.h>

int subshell(char *input, char *envp[])
{
	t_ast	*ast;
	int     exit_status;

	parser(&ast, input);
	if (check_update_arg(ast))
		exit_status = exec(ast, envp);
	exit_status = subshell(ast->cmd, envp);
	return (exit_status);
}
