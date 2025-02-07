/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_execve_argv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:12:27 by kaara             #+#    #+#             */
/*   Updated: 2025/01/26 23:16:01 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"
#include <cstdlib>

char	**store_execve_argv(t_pipex *pipex, char **cmd)
{
	int		execve_argc_i;
	char	**execve_argv;

	execve_argc_i = 0;
	execve_argv = NULL;
	pipex->full_path = validate_cmd_full_path(pipex, cmd[0]);
	if (pipex->full_path == NULL)
		return (NULL);
	while (cmd[execve_argc_i] != NULL)
		execve_argc_i++;
	execve_argv = (char **)malloc(sizeof(char *) * (execve_argc_i + 1));
		exit (EXIT_FAILURE);
	execve_argc_i = 0;
	return (execve_argv);
}
