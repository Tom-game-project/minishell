/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_full_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:31:20 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/21 18:32:09 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

static char	*join_path_and_free_func(char *a, void *b)
{
	char	*rstr;
	char	*tmp;

	tmp = ft_strjoin(a, "/");
	free(a);
	rstr = ft_strjoin(tmp, (char *) b);
	free(tmp);
	return (rstr);
}

static bool	check_exist_cmd(char *str)
{
	return (access(str, F_OK) == 0);
}

/// 
/// `char *cmd`
/// `char *env_path`
char	*get_full_path(char *cmd, char *env_path)
{
	t_str_list	*env_l;
	char		*rstr;

	if (check_exist_cmd(cmd))
		return (ft_strdup(cmd));
	if (env_path == NULL)
		return (NULL);
	env_l = NULL;
	env_l = str_list_split(env_path, ':');
	str_list_map_arg1(&env_l, join_path_and_free_func, cmd);
	rstr = str_list_search(env_l, check_exist_cmd);
	if (rstr == NULL)
	{
		str_list_clear(&env_l, free);
		return (NULL);
	}
	else
	{
		rstr = ft_strdup(rstr);
		str_list_clear(&env_l, free);
	}
	return (rstr);
}
