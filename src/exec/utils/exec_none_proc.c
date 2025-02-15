#include "dict.h"
#include "parser.h"
#include "exec.h"
#include "utils.h"

#include <sys/wait.h>
#include <unistd.h>

/// 実行可能な状態であり、かつ、
/// 自分自身が子プロセス中に入っていない場合(親プロセスから)実行される関数
int none_proc(t_exec_args *args)
{
	int pid;
	int status;
	int pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		return (-1);
	pid = fork();
	if (pid == 0)
	{
		if (args->input_fd != STDIN_FILENO)
		{
			dup2(args->input_fd, STDIN_FILENO);
			close(args->input_fd);
		}
		close(pipe_fd[PIPE_READ]);
		dup2(pipe_fd[PIPE_WRITE], STDOUT_FILENO);
		close(pipe_fd[PIPE_WRITE]);
		execve_wrap(args);
		return(1);
	}
	else
	{
		close(pipe_fd[PIPE_WRITE]);// 子プロセスに伝えることはない						
		fd_write(pipe_fd[PIPE_READ]);
		waitpid(pid, &status, WUNTRACED);
		close(pipe_fd[PIPE_READ]);
		return (WEXITSTATUS(status));
	}
}

