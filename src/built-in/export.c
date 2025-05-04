/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:26:08 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/30 19:56:36 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "envtools.h"
#include "libft.h"
#include "list.h"
#include "test_tools.h"
#include <stdlib.h>
#include <unistd.h>

///
///
///
///
/// ```bash
/// ❱ export hello=hello
/// ❱ export hello
/// ❱ echo $hello
/// hello
/// ```
///
///
/// ```bash
/// export hello=hello world=world
/// ```
///
/// ```
/// ❱ export =hello
/// bash: export: `=hello': not a valid identifier
/// ```

static int	set_envp(t_str_dict **envp_dict, char *key, char *value)
{
	if (ft_strlen(key) == 0)
	{
		return (1);
	}
	if (is_valid_identifier(key))
	{
		debug_dprintf(STDERR_FILENO, \
			"new env added key: \"%s\",value: \"%s\"\n", key, value);
		if (value == NULL)
			return (0);
		str_dict_add2(envp_dict, key, value);
		return (0);
	}
	else
	{
		return (1);
	}
}

int	built_in_export(t_str_list *args, t_str_dict **envp_dict)
{
	char	*line;
	char	*key;
	char	*value;

	args = args->next;
	while (args != NULL)
	{
		line = args->ptr.str;
		key = get_key_from_envp_ptr(line);
		value = get_value_from_envp_ptr(line);
		set_envp(envp_dict, key, value);
		free(key);
		free(value);
		args = args->next;
	}
	return (0);
}
