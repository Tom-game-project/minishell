/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc_o_proc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 20:42:48 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/21 20:45:50 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "exec.h"
#include "utils.h"

#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

static void	close_fd(t_exec_args *args)
{
	if (args->output_fd != STDOUT_FILENO)
		close(args->output_fd);
}

static int	open_func(char *path)
{
	return (open(path, O_APPEND | O_WRONLY, 0644));
}

static int	inner_exec(t_exec_args *args, int output_fd)
{
	if (args->ast->right_ast != NULL)
	{
		return (exec2(&(t_exec_args){\
			args->ast->right_ast, \
			args->envp_dict, \
			args->heredoc_fd_list, \
			args->input_fd, \
			output_fd, \
			-1}));
	}
	else if (args->ast->left_ast != NULL)
	{
		return (exec2(&(t_exec_args){\
			args->ast->left_ast, \
			args->envp_dict, \
			args->heredoc_fd_list, \
			args->input_fd, \
			output_fd, \
			-1}));
	}
	return (1);
}

int	exec_heredoc_o_proc(t_exec_args *args)
{
	return (
		exec_rdt_proc(
			args,
			close_fd,
			open_func,
			inner_exec
		)
	);
}
