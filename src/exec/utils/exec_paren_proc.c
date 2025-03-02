#include "exec.h"
#include "list.h"
#include "parser.h"
#include "../heredoc/heredoc.h"

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
	/// 子プロセス
	///
	/// heredocの外からは何もできない
	/// heredocがある場合になんとかしないといけない
	/// カッコ内にあるheredocをカウントしたい
	/// 
	/// fd = [1, 2, 3, 4, 5, 6];
	///
	/// ```
	/// shell cmd    fd_sub   fd_list 
	///  << 1        .-1      [1, 2, 3, 4, 5, 6];
	/// (<< 2 << 3)  .-2      [2, 3, 4, 5, 6]; // 親プロセスでは消してしまってok
	///  << 4        .-1      [4, 5, 6];
	/// (<< 5 << 6)  .-2      [5, 6];
	/// ```
	heredoc_c = count_heredoc(args->ast);
	if (pid == 0)
	{
		exec2(&(t_exec_args)
		{
			args->ast->left_ast,
			args->envp_dict,
			args->heredoc_fd_list,
			args->input_fd,
			args->output_fd,
			pid
		});
	       	// カッコの場合は子プロセス
		exit(0);
	}

	int i = 0;
	while (i < heredoc_c){
		int_list_pop(args->heredoc_fd_list,0);
		i += 1;
	}
	// 親プロセス
	waitpid(pid, &status, WUNTRACED);
	return (WEXITSTATUS(status));
}
