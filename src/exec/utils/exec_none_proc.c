#include "dict.h"
#include "list.h"
#include "parser.h"
#include "exec.h"
#include "utils.h"

#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

/// TODO:
/// リファクタリングをするときは、
/// 子プロセスと親プロセスで分ける

int child_proc_none(int pipe_fd[2],t_exec_args *args)
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

/// 返り値はexit_status
int parent_proc_none(int pipe_fd[2], int pid)
{
	int status;

	close(pipe_fd[PIPE_WRITE]);// 子プロセスに伝えることはない						
	fd_write(pipe_fd[PIPE_READ]);
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
	str_list_clear(&(args->args), free); // 実行のためにコマンドを使い終えたので消す
						      //
						      // フォークした子プロセスでは、有効
	return (parent_proc_none(pipe_fd, pid));
}

