/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:30:00 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/21 18:31:02 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "libft.h"
#include "strtools.h"

#include <dirent.h>
#include <stdlib.h>
#include <stdbool.h>

static bool is_dot_or_dotdot(t_anytype elem)
{
	return (ft_streq("..", elem.str) || ft_streq(".", elem.str));
}

t_str_list	*get_dir_list(char *name)
{
	DIR				*dir;
	struct dirent	*dp;
	t_str_list		*dlst;
	t_str_list		*junk;

	dlst = NULL;
	dir = opendir(name);
	if (dir == NULL)
		return (dlst);
	while (1)
	{
		dp = readdir(dir);
		if (dp == NULL)
			break ;
		str_list_push(&dlst, ft_strdup(dp->d_name));
	}
	closedir(dir);
	junk = void_list_filter(&dlst, is_dot_or_dotdot);
	str_list_clear(&junk, free);
	return (dlst);
}
