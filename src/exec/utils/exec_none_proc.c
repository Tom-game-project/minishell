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

/// TODO:
/// リファクタリングをするときは、
/// 子プロセスと親プロセスで分ける

int	child_proc_none(int pipe_fd[2], t_exec_args *args)
{
	if (args->input_fd != STDIN_FILENO)
	{
		dup2(args->input_fd, STDIN_FILENO);
		close(args->input_fd);
	}
	close(pipe_fd[PIPE_READ]);
	dup2(pipe_fd[PIPE_WRITE], STDOUT_FILENO);
	close(pipe_fd[PIPE_WRITE]);
	if (args->output_fd != STDOUT_FILENO)
	{
		dup2(args->output_fd, STDOUT_FILENO);
		close(args->output_fd);
	}
	execve_wrap(args);
	return (1);
}

/// 返り値はexit_status
int	parent_proc_none(int pipe_fd[2], t_exec_args *args, int pid)
{
	int	status;
	int	exit_status;

	close(pipe_fd[PIPE_WRITE]);
	fd_write(pipe_fd[PIPE_READ], args->output_fd);
	waitpid(pid, &status, WUNTRACED);
	close(pipe_fd[PIPE_READ]);
	exit_status = WEXITSTATUS(status);
	return (exit_status);
}


/// 実行可能な状態であり、かつ、
/// 自分自身が子プロセス中に入っていない場合(親プロセスから)実行される関数
int	none_proc(t_exec_args *args)
{
	int	pid;
	int	pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		return (-1);
	pid = fork();
	if (pid == 0)
	{
		child_proc_none(pipe_fd, args);
	}
	return (parent_proc_none(pipe_fd, args, pid));
}

