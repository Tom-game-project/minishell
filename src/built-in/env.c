/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:23:24 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/12 19:23:24 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "dict.h"

#include <unistd.h>
#include <stdlib.h>

/// env with no options or arguments
///
///
int	built_in_env(t_str_dict *envp_dict, int fd)
{
	int		exit_status;
	char	**envp;
	int		i;

	exit_status = 0;
	envp = str_dict_to_envp(envp_dict);
	i = 0;
	while (envp[i] != NULL)
	{
		ft_putstr_fd(envp[i], fd);
		ft_putstr_fd("\n", fd);
		i += 1;
	}
	i = 0;
	while (envp[i] != NULL)
	{
		free(envp[i]);
		i += 1;
	}
	free(envp);
	return (exit_status);
}
