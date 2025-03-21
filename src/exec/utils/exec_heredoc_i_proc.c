/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc_i_proc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:48:34 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/21 18:50:14 by tmuranak         ###   ########.fr       */
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
	if (args->input_fd != STDIN_FILENO)
		close(args->input_fd);
}

static int	inner_exec(t_exec_args *args, int input_fd)
{
	if (args->ast->right_ast != NULL)
	{
		exec2(&(t_exec_args)
		{
			args->ast->right_ast,
			args->envp_dict,
			args->heredoc_fd_list,
			input_fd,
			args->output_fd,
			-1
		});
	}
	else if (args->ast->left_ast != NULL)
	{
		exec2(&(t_exec_args)
		{
			args->ast->left_ast,
			args->envp_dict,
			args->heredoc_fd_list,
			input_fd,
			args->output_fd,
			-1
		});
	}
	return (0);
}

int	exec_heredoc_i_proc(t_exec_args *args)
{
	return (
		exec_rdt_proc_heredoc(
			args,
			close_fd,
			inner_exec
		)
	);
}
