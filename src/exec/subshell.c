
#include "built_in.h"
#include "exec.h"
#include "parser.h"
#include "pipe.h"
#include <stdbool.h>

int subshell(char *input, char *envp[])
{
	t_ast	*ast;
	int     exit_status;

	if (input == NULL)
		return (0);
	parser(&ast, input);

	tinyshell(ast, envp)
	{

		if (check_update_arg(ast))
			exit_status = exec(ast, envp);
		exit_status = subshell(ast->cmd, envp);
		if (check_logical_operator(ast->right_ast))
			(ast->right_ast);
	}

	return (exit_status);
}

//pipexと違って>が存在しない場合stdoutにpipe内のものを最後に出力する必要がある。
//andとor演算子を見て処理するか確認する関数が必要