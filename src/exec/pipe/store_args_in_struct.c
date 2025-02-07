/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_args_in_struct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:26:55 by kaara             #+#    #+#             */
/*   Updated: 2025/01/21 15:26:55 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

void	store_args_in_struct(t_pipex *pipex, int argc, char **argv)
{
	pipex->infile_name = allocation_and_cpy(pipex, argv[1]);
	pipex->outfile_name = allocation_and_cpy(pipex, argv[argc - 1]);
	pipex->cmdc = argc - 2 - 1;
	pipex->cmdc_i = 0;
	pipex->pipe_fd[0] = 0;
	pipex->pipe_fd[1] = 1;
	pipex->cmdv = (char ***)malloc(sizeof(char **) * (pipex->cmdc + 1));
	if (pipex->cmdv == NULL)
		free_exit(pipex, 1);
	while (pipex->cmdc_i < pipex->cmdc)
	{
		pipex->cmdv[pipex->cmdc_i] = ft_split(argv[pipex->cmdc_i + 1 + 1], ' ');
		if (pipex->cmdv[pipex->cmdc_i] == NULL)
			free_exit(pipex, 1);
		pipex->cmdc_i++;
	}
	pipex->cmdv[pipex->cmdc_i] = NULL;
	pipex->cmdc_i = 0;
}
