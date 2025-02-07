/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_setup_pipefd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:25:15 by kaara             #+#    #+#             */
/*   Updated: 2025/01/21 15:25:15 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

void	setup_pipefd(t_pipex *pipex, int cmdc_i)
{
	if (cmdc_i != 0)
	{
		if (dup2(pipex->pipe_fd[0], STDIN_FILENO) == -1)
		{
			perror("dup2 return -1.");
			free_exit(pipex, EXIT_FAILURE);
		}
		close(pipex->pipe_fd[0]);
	}	
	if (pipe(pipex->pipe_fd) == -1)
	{
		perror("pipe return -1.");
		free_exit(pipex, EXIT_FAILURE);
	}
	if (dup2(pipex->pipe_fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2 return -1.");
		free_exit(pipex, EXIT_FAILURE);
	}
	close(pipex->pipe_fd[1]);
}
