#include "exec.h"
#include "parser.h"
#include "../heredoc/heredoc.h"
#include "utils.h"
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

	pid = fork();
	if (pid == 0)
	{
		dup2(args->input_fd, STDIN_FILENO);
		dup2(args->output_fd, STDOUT_FILENO);
		exec2(&(t_exec_args)
		{
			args->ast->left_ast,
			args->envp_dict,
			args->heredoc_fd_list,
			args->input_fd,
			args->output_fd,
			pid
		});
		close(args->input_fd);
		close(args->output_fd);
		exit(0);
	}
	/// 子プロセスで読まれたheredocをskipする
	heredoc_c = count_heredoc(args->ast);
	consume_fd(heredoc_c, args->heredoc_fd_list);
	// 親プロセス
	waitpid(pid, &status, WUNTRACED);
	return (WEXITSTATUS(status));
}
