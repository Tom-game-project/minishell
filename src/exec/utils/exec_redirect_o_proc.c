#include "list.h"
#include "parser.h"
#include "exec.h"
#include "libft.h"
#include "utils.h"

#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int exec_redirect_o_proc(t_exec_args *args)
{
	char *str;
	t_str_list *args_list;
	int output_fd;

	args_list = NULL;
	if (args->output_fd != STDOUT_FILENO)
	{
		close(args->output_fd);
	}
	str = str_list_get_elem(args->ast->arg, 0);
	output_fd = open(str,  O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_fd == -1)
	{
		perror("minishell"); // TODO
	}
	if (args->ast->left_ast != NULL && args->ast->left_ast->ope == e_ope_none){
		// -- .2
		str_list_concat(
				&args_list,
			       	str_list_clone(
					args->ast->left_ast->arg,
				       	ft_strdup));
	}
	if (args->ast->right_ast != NULL)
	{
		exec2(&(t_exec_args)
		{
		    args->ast->right_ast,
		    args->envp_dict,
		    args_list,
		    STDIN_FILENO, 
		    output_fd,
		    -1 // 子プロセスを生み出すため
		});
	}
	else if (args->ast->left_ast != NULL)
	{
		exec2(&(t_exec_args)
		{
		    args->ast->left_ast,
		    args->envp_dict,
		    NULL,
		    STDIN_FILENO,
		    output_fd,
		    -1 // 子プロセスを生み出すため
		});
	} // TODO:考える
	close(output_fd);
	return (0);
}
