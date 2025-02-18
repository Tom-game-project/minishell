#include "dict.h"
#include "parser.h"
#include "exec.h"

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

/// 子プロセス
static int child_proc_and(t_exec_args *args, int pid)
{
	// 子
	if (args->input_fd != STDIN_FILENO)
	{
		dup2(args->input_fd, STDIN_FILENO);
		close(args->input_fd);
	}
	exec2(
		&(t_exec_args)
		{
			args->ast->left_ast,
			args->envp_dict,
			args->args,
			args->input_fd,
			pid
		});
	exit(0);
	return (1);
}

/// 親プロセス
static int parent_proc_and(t_exec_args *args, int pid)
{
	int status;

	if (args->input_fd != STDIN_FILENO)
		close(args->input_fd);
	waitpid(pid, &status, WUNTRACED);
	if (WEXITSTATUS(status) != 0) //正常に終了しなかった場合
	{
		return (WEXITSTATUS(status));
	}
	else // 正常に終了した場合次のコマンドを実行
		return (exec2(
			&(t_exec_args)
				{
					args->ast->right_ast,
					args->envp_dict,
					args->args,
					STDIN_FILENO,
					pid
				}));
}


int and_proc(t_exec_args *args)
{
	int pid;

	pid = fork();
	if (pid == 0) // 子
		return (child_proc_and(args, pid));
	else
		// 親
		return (parent_proc_and(args, pid));
}

