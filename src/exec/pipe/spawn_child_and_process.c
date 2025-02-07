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

#include "parser.h"
#include "pipe.h"

int	spawn_child_and_process(t_ast *ast, t_pipex	*pipex, char *envp[])
{
	pid_t	pid;
	int		exit_status;
	int		pre_exit_status;

	if (ast == NULL)
		return (0);
	else if (ast->rdtope != e_rdtope_none)
		spawn_child_and_process(ast->right_ast, pipex, envp);
	else
	{
		setup_pipefd(ast, pipex);
		pid = fork();
		if (pid < 0)
			false_fork(pipex);
		else if (pid == 0)
			spawn_child_and_process(ast, pipex, envp);
		exit_status = spawn_child_and_process(ast->right_ast, pipex, envp);
	}
	if (cmdc_i == pipex->cmdc - 1)
	{
		waitpid(pid, &pre_exit_status, 0);
		exit_status = WEXITSTATUS(pre_exit_status);
	}
	else
		waitpid(pid, &pre_exit_status, 0);
	return (exit_status);
}
