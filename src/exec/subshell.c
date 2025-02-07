
#include "exec.h"
#include "parser.h"
#include "pipe.h"
#include <stdbool.h>

int	tinyshell(t_ast *ast, char *envp[]);

int subshell(char *input, char *envp[])//ast全体の処理。
{
	t_ast	*ast;
	int     exit_status;

	if (input == NULL)
		return (-1);
	parser(&ast, input);
	exit_status = tinyshell(ast, envp);
	return (exit_status);
}

int	tinyshell(t_ast *ast, char *envp[])//astの中身を処理する再起。
{
	int     exit_status;

	if (ast->right_ast == NULL)//終了条件。
			return (-1);
	if (check_update_arg(ast))
		exit_status = exec(ast, envp);//実行可能な状態でastが渡される。ほぼほぼpipe
	else
	{
		exit_status = subshell(ast->cmd, envp);//コマンドがまだ分割できる段階。
		if (exit_status == -1)
			exit_status = tinyshell(ast, envp);//分割は済んだけど"'(で囲まれてたり環境変数が存在した場合。
	}
	if (check_logical_operator(ast->right_ast, exit_status))//ctlopeの条件によって実行を継続可能か判断する。
			return (exit_status);
	exit_status = tinyshell(ast->right_ast, envp);
	return (exit_status);
}

//pipexと違って>が存在しない場合stdoutにpipe内のものを最後に出力する必要がある。
