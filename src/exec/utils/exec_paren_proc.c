#include "exec.h"
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

/// parenは特別なデータ形式
/// right_astを持たない
int paren_proc(t_exec_args *args)
{
	int pid;
	int status;

	pid = fork();
	if (pid == 0)
	// 子プロセス
	{
		exec2(&(t_exec_args){
			args->ast->left_ast,
			args->envp_dict,
			args->heredoc_fd_list,
			args->input_fd,
			args->output_fd,
			pid
		}); // カッコの場合は子プロセス
		exit(0);
	}
	// 親プロセス
	waitpid(pid, &status, WUNTRACED);
	return (WEXITSTATUS(status));
}
