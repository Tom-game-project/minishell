#include "utils.h"

#include <sys/wait.h>
#include <unistd.h>

/// TODO:
/// リファクタリングをするときは、
/// 子プロセスと親プロセスで分ける

int child_proc_none(int pipe_fd[2], t_exec_args *args)
{
	if (args->input_fd != STDIN_FILENO)
	{
		dup2(args->input_fd, STDIN_FILENO);
		close(args->input_fd);
	}
	close(pipe_fd[PIPE_READ]);
	dup2(pipe_fd[PIPE_WRITE], STDOUT_FILENO);
	close(pipe_fd[PIPE_WRITE]);
	if (args->output_fd != STDOUT_FILENO)
	{
		dup2(args->output_fd, STDOUT_FILENO);
		close(args->output_fd);
	}
	execve_wrap(args);
	return(1);
}

/// 返り値はexit_status
int parent_proc_none(int pipe_fd[2], t_exec_args *args, int pid)
{
	int status;

	close(pipe_fd[PIPE_WRITE]);// 子プロセスに伝えることはない
	fd_write(pipe_fd[PIPE_READ], args->output_fd);
	waitpid(pid, &status, WUNTRACED);
	close(pipe_fd[PIPE_READ]);
	return (WEXITSTATUS(status));
}


/// 実行可能な状態であり、かつ、
/// 自分自身が子プロセス中に入っていない場合(親プロセスから)実行される関数
int none_proc(t_exec_args *args)
{
	int pid;
	int pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		return (-1);
	pid = fork();
	if (pid == 0)
	{
		child_proc_none(pipe_fd, args);
	}
	return (parent_proc_none(pipe_fd, args , pid));
}

