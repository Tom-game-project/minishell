#include "exec.h"
#include "list.h"
#include "parser.h"
#include "../heredoc/heredoc.h"
#include "test_tools.h"

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

/// parenは特別なデータ形式
/// right_astを持たない
int paren_proc(t_exec_args *args)
{
	int pid;
	int status;
	int heredoc_c;

	heredoc_c = count_heredoc(args->ast);
	pid = fork();
	if (pid == 0)
	{
		dup2(args->input_fd, STDIN_FILENO);
		exec2(&(t_exec_args)
		{
			args->ast->left_ast,
			args->envp_dict,
			args->heredoc_fd_list,
			args->input_fd,
			args->output_fd,
			pid
		});
		exit(0);
	}
	/// 子プロセスで読まれたheredocをskipする
	int i = 0;
	while (i < heredoc_c){
		int fd;
		fd = int_list_pop(args->heredoc_fd_list, 0);
		close(fd);
		i += 1;
	}
	// 親プロセス
	waitpid(pid, &status, WUNTRACED);
	return (WEXITSTATUS(status));
}
