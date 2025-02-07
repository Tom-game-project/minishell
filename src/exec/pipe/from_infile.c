/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_from_infile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:25:20 by kaara             #+#    #+#             */
/*   Updated: 2025/01/21 15:25:20 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

#include <stdio.h>

void	from_infile(t_pipex *pipex)
{
	pipex->infile_fd = open(pipex->infile_name, O_RDONLY);
	if (pipex->infile_fd == -1)
	{
		perror("open(infile_name, O_RDONLY); return -1.\n");
		free_exit(pipex, 1);
	}
	else if (dup2(pipex->infile_fd, STDIN_FILENO) == -1)
	{
		perror("dup2 return -1.\n");
		free_exit(pipex, 1);
	}
	close(pipex->infile_fd);
}
