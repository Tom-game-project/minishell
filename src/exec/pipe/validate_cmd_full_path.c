/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_cmd_full_path.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:48:56 by kaara             #+#    #+#             */
/*   Updated: 2025/01/21 20:48:56 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

#include "libft.h"
#include <stdio.h>

char	*validate_cmd_full_path(t_pipex *pipex, char *cmd)
{
	int		i;
	char	*add_slash;
	char	*full_path;

	i = 0;
	while (pipex->path[i] != NULL)
	{
		add_slash = ft_strjoin(pipex->path[i], "/");
		if (add_slash == NULL)
			free_exit(pipex, 1);
		full_path = ft_strjoin(add_slash, cmd);
		if (full_path == NULL)
			free_exit(pipex, 1);
		free(add_slash);
		add_slash = NULL;
		if (access(full_path, X_OK) == 0)
			break ;
		free(full_path);
		full_path = NULL;
		i++;
	}
	if (full_path == NULL)
		perror ("Not found command full_path.");
	return (full_path);
}

