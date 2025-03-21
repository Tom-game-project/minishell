/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_none_proc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:52:01 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/21 18:52:53 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <sys/wait.h>
#include <unistd.h>

// TODO: ここでパイプは必要ない

int	child_proc_none(t_exec_args *args)
{
	if (args->input_fd != STDIN_FILENO)
	{
		dup2(args->input_fd, STDIN_FILENO);
		close(args->input_fd);
	}
	if (args->output_fd != STDOUT_FILENO)
	{
		dup2(args->output_fd, STDOUT_FILENO);
		close(args->output_fd);
	}
	execve_wrap(args);
	return (1);
}

/// 返り値はexit_status
int	parent_proc_none(t_exec_args *args, int pid)
{
	int	status;
	int	exit_status;

	if (args->input_fd != STDIN_FILENO)
	{
		close(args->input_fd);
	}
	waitpid(pid, &status, WUNTRACED);
	exit_status = WEXITSTATUS(status);
	return (exit_status);
}

/// 実行可能な状態であり、かつ、
/// 自分自身が子プロセス中に入っていない場合(親プロセスから)実行される関数
int	none_proc(t_exec_args *args)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		child_proc_none(args);
	}
	return (parent_proc_none(args, pid));
}

