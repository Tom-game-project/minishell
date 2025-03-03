#include "parser.h"
#include "exec.h"

#include <sys/wait.h>
#include <unistd.h>
#include <stdbool.h>

/// 逐次的な処理
/// (前回実行した処理のexit statusによって
/// 次の処理をするか否かを決定するような処理)
/// の抽象関数
///
/// impl 
/// 以下の関数で使用されている
/// - and_proc
/// - or_proc
int sequential_proc(t_exec_args *args, bool (*f)(int))
{
	int exit_status;

	exit_status = exec2(
		&(t_exec_args)
		{
			args->ast->left_ast,
			args->envp_dict,
			args->args,
			args->input_fd,
			args->output_fd,
			-1
		});
	if (f(exit_status))
	{
		return (exec2(
			&(t_exec_args)
			{
				args->ast->right_ast,
				args->envp_dict,
				args->args,
				args->input_fd,
				args->output_fd,
				-1
			})
		);
	}
	return (exit_status);

}
