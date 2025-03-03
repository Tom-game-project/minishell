#include "parser.h"
#include "exec.h"

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

/// 子プロセス
static int child_proc_pipe(int pipe_fd[2], t_exec_args *args, int pid)
{
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
			args->output_fd, 
			pid
		}
	);
	exit(1); // exit status
	return (0);
}

/// 親プロセス
static int parent_proc_pipe(int pipe_fd[2], t_exec_args *args, int pid)
{
	int exit_status;

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
			STDOUT_FILENO,
			pid
		}
	);
	close(pipe_fd[PIPE_READ]);
	waitpid(pid, NULL, WUNTRACED);
	return (exit_status);
}

/// exit_statusを返却する
int pipe_proc(t_exec_args *args)
{
	int pid;
	int pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		// パイプの生成に失敗 , TODO: perrorを出力するように
		return (1);
	pid = fork();
	if (pid == 0)
		// 子
		return (child_proc_pipe(pipe_fd, args, pid));
	else
		// 親
		return (parent_proc_pipe(pipe_fd, args, pid));
}
