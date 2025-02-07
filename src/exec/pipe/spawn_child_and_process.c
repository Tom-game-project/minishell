/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_child_and_process.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:22:01 by kaara             #+#    #+#             */
/*   Updated: 2025/01/29 19:53:05 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

int	spawn_child_and_process(t_pipex	*pipex, char *const *envp, int cmdc_i)
{
	pid_t	pid;
	int		exit_status;
	int		pre_exit_status;

	if (cmdc_i >= pipex->cmdc)
		return (0);
	setup_pipefd(pipex, cmdc_i);
	pid = fork();
	if (pid < 0)
		false_fork(pipex);
	else if (pid == 0)
		chiled_process(pipex, envp, cmdc_i);
	exit_status = spawn_child_and_process(pipex, envp, cmdc_i + 1);
	if (cmdc_i == pipex->cmdc - 1)
	{
		waitpid(pid, &pre_exit_status, 0);
		exit_status = WEXITSTATUS(pre_exit_status);
	}
	else
		waitpid(pid, &pre_exit_status, 0);
	return (exit_status);
}
