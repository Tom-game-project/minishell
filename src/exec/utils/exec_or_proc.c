#include "dict.h"
#include "parser.h"
#include "exec.h"

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int or_proc(t_exec_args *args)
{
	int pid;
	int status;

	pid = fork();
	if (pid == 0)
	{ // 子
		if (args->input_fd != STDIN_FILENO)
		{
			dup2(args->input_fd, STDIN_FILENO);
			close(args->input_fd);
		}
		exec2(
		&(t_exec_args){
			args->ast->left_ast,
			args->envp_dict, 
			args->args,
			args->input_fd, 
			pid
		});
		exit(0);
	} // 親
	if (args->input_fd != STDIN_FILENO)
		close(args->input_fd);
	waitpid(pid, &status, WUNTRACED);
	if (WEXITSTATUS(status) == 0) //正常に終了した場合
	{
		return (WEXITSTATUS(status)); // TODO ここで何を返すべきか確かめる
	}
	else // 正常に終了しなかった場合は次のコマンドを実行
		return (exec2(
		&(t_exec_args){
			args->ast->right_ast,
			args->envp_dict, 
			args->args,
			STDIN_FILENO, 
			pid
		})
	);
}
