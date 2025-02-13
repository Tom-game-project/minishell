#include "dict.h"
#include "parser.h"
#include "exec.h"

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int or_proc(t_ast *ast, t_str_dict *envp_dict, int input_fd)
{
	int pid;
	int status;

	pid = fork();
	if (pid == 0)
	{ // 子
		if (input_fd != STDIN_FILENO)
		{
			dup2(input_fd, STDIN_FILENO);
			close(input_fd);
		}
		exec2(ast->left_ast, envp_dict, input_fd, pid); // 
		exit(0);
	} // 親
	if (input_fd != STDIN_FILENO)
		close(input_fd);
	waitpid(pid, &status, WUNTRACED);
	if (WEXITSTATUS(status) == 0) //正常に終了した場合
	{
		return (WEXITSTATUS(status)); // TODO ここで何を返すべきか確かめる
	}
	else // 正常に終了しなかった場合は次のコマンドを実行
		return (exec2(ast->right_ast, envp_dict, STDIN_FILENO, pid));
}
