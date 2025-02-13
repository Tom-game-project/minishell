#include "dict.h"
#include "parser.h"
#include "exec.h"

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

/// exit_statusを返却する
int pipe_proc(t_ast *ast, t_str_dict *envp_dict, int input_fd)
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
		if (input_fd != STDIN_FILENO)
		{
			dup2(input_fd, STDIN_FILENO);
			close(input_fd);
		}
		close(pipe_fd[PIPE_READ]);
		dup2(pipe_fd[PIPE_WRITE], STDOUT_FILENO);
		close(pipe_fd[PIPE_WRITE]);
		exec2(ast->left_ast, envp_dict, input_fd, pid); // 
		exit(0);
	} // 親
	close(pipe_fd[PIPE_WRITE]);
	if (input_fd != STDIN_FILENO)
		close(input_fd);
	exit_status = exec2(ast->right_ast, envp_dict, pipe_fd[PIPE_READ], pid);
	waitpid(pid, NULL, WUNTRACED);
	return (exit_status);
}
