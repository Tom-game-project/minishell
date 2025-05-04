/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_paren_proc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:53:18 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/21 20:49:17 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "parser.h"
#include "../heredoc/heredoc.h"
#include "utils.h"
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

static int	paren_proc_children(t_exec_args *args)
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
		0
	});
	close(args->input_fd);
	close(args->output_fd);
	exit(0);
}

int	paren_proc(t_exec_args *args)
{
	int	pid;
	int	status;
	int	heredoc_c;

	pid = fork();
	if (pid == 0)
	{
		paren_proc_children(args);
	}
	heredoc_c = count_heredoc(args->ast);
	consume_fd(heredoc_c, args->heredoc_fd_list);
	waitpid(pid, &status, WUNTRACED);
	return (WEXITSTATUS(status));
}
