/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_none_proc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:52:01 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/30 20:02:36 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "utils.h"
#include <sys/wait.h>
#include <unistd.h>

// TODO: ここでパイプは必要ない
int	child_proc_none2(
	int input_fd, int output_fd, t_str_list *args, t_str_dict *envp_dict)
{
	if (input_fd != STDIN_FILENO)
	{
		dup2(input_fd, STDIN_FILENO);
		close(input_fd);
	}
	if (output_fd != STDOUT_FILENO)
	{
		dup2(output_fd, STDOUT_FILENO);
		close(output_fd);
	}
	execve_wrap2(args, envp_dict);
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
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGINT)
			exit_status = 130;
	}
	return (exit_status);
}

int	parent_proc_none2(int input_fd, int pid)
{
	int	status;
	int	exit_status;

	if (input_fd != STDIN_FILENO)
	{
		close(input_fd);
	}
	waitpid(pid, &status, WUNTRACED);
	exit_status = WEXITSTATUS(status);
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGINT)
			exit_status = 130;
	}
	return (exit_status);
}

/// 実行可能な状態であり、かつ、
/// 自分自身が子プロセス中に入っていない場合(親プロセスから)実行される関数
int	none_proc2(
	int input_fd, int output_fd, t_str_list *args, t_str_dict *envp_dict)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		child_proc_none2(input_fd, output_fd, args, envp_dict);
	}
	return (parent_proc_none2(input_fd, pid));
}
