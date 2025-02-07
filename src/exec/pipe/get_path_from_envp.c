/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_from_envp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:36:50 by kaara             #+#    #+#             */
/*   Updated: 2025/01/26 15:52:58 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

#include "libft.h"
#include <stdio.h>

char	**get_path_from_envp(char *const *envp, t_pipex *pipex)
{
	int		i;
	char	**path;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", sizeof(char) * 5) == 0)
			break ;
		i++;
	}
	if (envp[i] == NULL)
	{
    	perror("PATH not found in envp");
    	free_exit(pipex, 1);
	}
	path = ft_split(envp[i] + 5, ':');
	if (path == NULL)
	{
		perror("ft_sprit return NULL");
		free_exit(pipex, 1);
	}
	return (path);
}
