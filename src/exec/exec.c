
#include "dict.h"
#include "parser.h"
#include <unistd.h>
#include <stdio.h>


//int exec_(t_ast *ast, t_str_dict *envp_dict)
//{
//	int exit_status;
//
//	exit_status = 0;
//	return (exit_status);
//}

//int pipe_exec()
//{
//	int		pipe_fd[2];
//
//	if (pipe(pipe_fd) == -1)
//		return (perror("pipe"), 1);
//	return (0);
//}

int exec(t_ast *ast, t_str_dict *envp_dict, int input_fd)
{
	int exit_status;
	int pipe_fd[2];
	int pid;

	exit_status = 0;
	if (ast->ope == e_ope_pipe)
	{
		// パイプ
		// もう実行できる状態
		pid = fork();
		if (pid == 0)
		{
			// 子
		}
		else
		{
			// 親
			
		}
	}
	else if (ast->ope == e_ope_none)
	{

	}
	else
	{
		dprintf(STDERR_FILENO, "unexpected ope!\n");
	}
	return (exit_status);
}
