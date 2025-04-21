/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:25:12 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/12 19:25:12 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "list.h"
#include "libft.h"
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

// for test
// #include <stdio.h>

static bool	is_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i += 1;
	while (str[i] == '\0')
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i += 1;
	}
	return (true);
}

int	built_in_exit(t_str_list *args, t_str_dict *env_dict)
{
	char		*str;
	t_str_dict	*exit_status_tmp;

	ft_putstr_fd("exit\n", STDERR_FILENO);
	if (str_list_len(args) == 1)
	{
		exit_status_tmp = get_str_dict_by_key(env_dict, "?");
		exit(ft_atoi(exit_status_tmp->value));
	}
	else
	{
		str = str_list_get_elem(args, 1);
		if (is_num(str))
			exit(ft_atoi(str) % 256);
		else
			exit(2);
	}
	return (2);
}
