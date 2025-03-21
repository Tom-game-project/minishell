/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe_proc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:53:55 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/21 18:55:45 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "parser.h"
#include "exec.h"
#include "../heredoc/heredoc.h"
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

/// 子プロセスで使用されたであろう子プロセスを親側で閉じる関数
int	consume_fd(int heredoc_c, t_int_list **heredoc_fd_list)
{
	int	i;

	i = 0;
	while (i < heredoc_c)
	{
		int fd;
		fd = int_list_pop(heredoc_fd_list, 0);
		close(fd);
		i += 1;
	}
	return (0);
}

/// 子プロセス
static int	child_proc_pipe(int pipe_fd[2], t_exec_args *args, int pid)
{
	if (args->input_fd != STDIN_FILENO)
	{
		dup2(args->input_fd, STDIN_FILENO);
		close(args->input_fd);
	}
	close(pipe_fd[PIPE_READ]);
	dup2(pipe_fd[PIPE_WRITE], STDOUT_FILENO);
	close(pipe_fd[PIPE_WRITE]);
	exec2(&(t_exec_args){
		args->ast->left_ast,
		args->envp_dict,
		args->heredoc_fd_list,
		STDIN_FILENO,
		STDOUT_FILENO,
		pid});
	exit(1);
	return (0);
}

/// 親プロセス
static int	parent_proc_pipe(int pipe_fd[2], t_exec_args *args, int pid)
{
	int	exit_status;

	close(pipe_fd[PIPE_WRITE]);
	if (args->input_fd != STDIN_FILENO)
		close(args->input_fd);
	exit_status = exec2(&(t_exec_args)
		{
			args->ast->right_ast,
			args->envp_dict,
			args->heredoc_fd_list,
			pipe_fd[PIPE_READ],
			STDOUT_FILENO,
			pid
		});
	waitpid(pid, NULL, WUNTRACED);
	return (exit_status);
}

/// exit_statusを返却する
int	pipe_proc(t_exec_args *args)
{
	int	pid;
	int	pipe_fd[2];
	int	heredoc_c;

	if (pipe(pipe_fd) == -1)
		return (1);
	pid = fork();
	if (pid == 0)
		return (child_proc_pipe(pipe_fd, args, pid));
	heredoc_c = count_heredoc(args->ast->left_ast);
	consume_fd(heredoc_c, args->heredoc_fd_list);
	return (parent_proc_pipe(pipe_fd, args, pid));
}
