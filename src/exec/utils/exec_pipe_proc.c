#include "parser.h"
#include "exec.h"

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

/// exit_statusを返却する
int pipe_proc(t_exec_args *args)
{
	int pid;
	int pipe_fd[2];
	int exit_status;

	if (pipe(pipe_fd) == -1)
		// パイプの生成に失敗
		return (1);
	pid = fork();
	if (pid == 0)
	{ // 子
		if (args->input_fd != STDIN_FILENO)
		{
			dup2(args->input_fd, STDIN_FILENO);
			close(args->input_fd);
		}
		close(pipe_fd[PIPE_READ]);
		dup2(pipe_fd[PIPE_WRITE], STDOUT_FILENO);
		close(pipe_fd[PIPE_WRITE]);
		exec2(
			&(t_exec_args)
			{
				args->ast->left_ast,
				args->envp_dict, 
				args->args,
				args->input_fd, 
				pid
			}
		);
				
		exit(0);
	} // 親
	close(pipe_fd[PIPE_WRITE]);
	if (args->input_fd != STDIN_FILENO)
		close(args->input_fd);
	exit_status = exec2(
		&(t_exec_args)
		{
			args->ast->right_ast,
			args->envp_dict, 
			args->args,
			pipe_fd[PIPE_READ], 
			pid
		}
	);
	waitpid(pid, NULL, WUNTRACED);
	return (exit_status);
}
