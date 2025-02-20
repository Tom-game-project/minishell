#include "exec.h"
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

///
int paren_proc(t_exec_args *args)
{
	int pid;
	int status;

	pid = fork();
	if (pid == 0)
	// 子プロセス
	{
		exec2(args); // カッコの場合は子プロセス
		exit(0);
	}
	// 親プロセス
	waitpid(pid, &status, WUNTRACED);
	return (WEXITSTATUS(status));
}
