#include "parser.h"
#include "exec.h"
#include "utils.h"

#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

static void close_fd(t_exec_args *args)
{
	if (args->input_fd != STDIN_FILENO)
		close(args->input_fd);
}

static int inner_exec(t_exec_args *args, int input_fd)
{
	if (args->ast->right_ast != NULL)
	{
		return (exec2(&(t_exec_args)
		{
		    args->ast->right_ast,
		    args->envp_dict,
		    args->heredoc_fd_list,
		    input_fd, 
		    args->output_fd,
		    -1 // 子プロセスを生み出すため
		}));
	}
	else if (args->ast->left_ast != NULL)
	{
		return (exec2(&(t_exec_args)
		{
		    args->ast->left_ast,
		    args->envp_dict,
		    args->heredoc_fd_list,
		    input_fd,
		    args->output_fd,
		    -1 // 子プロセスを生み出すため
		}));
	}
	return (0);
}

int exec_heredoc_i_proc(t_exec_args *args)
{
	return (
		exec_rdt_proc_heredoc(
			args,
			close_fd,
			inner_exec
		)
	);
}
