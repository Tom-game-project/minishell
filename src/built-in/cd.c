/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 18:24:24 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/22 18:24:24 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "list.h"
#include "libft.h"
#include "strtools.h"
#include "test_tools.h"
#include "err_msg.h"

#include <linux/limits.h>
#include <unistd.h>
#include <stdio.h>

#define OLDPWD "OLDPWD"
#define HOME "HOME"

static char	*get_cd(void)
{
	char	buf[PATH_MAX];

	if (getcwd(buf, PATH_MAX) == NULL)
	{
		perror("minishell");
		return (ft_strdup(""));
	}
	return (ft_strdup(buf));
}

static int	update_oldpwd(t_str_dict **envp_list)
{
	char	*key_str;

	key_str = ft_strdup(OLDPWD);
	if (str_dict_add(envp_list, key_str, get_cd(), free) == 0)
		free(key_str);
	return (1);
}

static char	*get_cd_path(t_str_list *args, t_str_dict **envp_list)
{
	char		*path;
	t_str_dict	*d;

	if (str_list_len(args) == 1)
	{
		d = get_str_dict_by_key(*envp_list, HOME);
		if (d == NULL || ft_streq(d->value, ""))
			return (report_cd_home_not_set(), NULL);
		return (ft_strdup(d->value));
	}
	path = str_list_get_elem(args, 1);
	if (ft_streq(path, "-"))
	{
		d = get_str_dict_by_key(*envp_list, OLDPWD);
		if (d == NULL || ft_streq(d->value, ""))
			return (report_cd_oldpwd_not_set(), NULL);
		return (ft_strdup(d->value));
	}
	else
		return (ft_strdup(path));
}

/// ```bash
/// cd 
/// ```
/// ## case
/// - return exit_status
///
int	built_in_cd(t_str_list *args, t_str_dict **envp_list)
{
	char	*path;

	if (2 < str_list_len(args))
	{
		report_cd_too_many_arguments();
		return (1);
	}
	path = get_cd_path(args, envp_list);
	if (path == NULL)
		return (1);
	update_oldpwd(envp_list);
	debug_dprintf(STDERR_FILENO, "cd \"%s\"\n", path);
	if (chdir(path) == -1)
	{
		perror("minishell");
		free(path);
		return (1);
	}
	free(path);
	return (0);
}
