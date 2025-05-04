/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_dict_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:28:39 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/21 18:06:52 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "libft.h"
#include <stdlib.h>

// for test
#include <stdio.h>

///
///
///
int	str_dict_add(t_str_dict **node, char *key, char *value, void (*f)(void *))
{
	t_str_dict	*sd;

	sd = get_str_dict_by_key(*node, key);
	if (sd == NULL)
	{
		str_dict_push(node, key, value);
		return (1);
	}
	else
	{
		f(sd->value);
		sd->value = value;
		return (0);
	}
}

///
int	str_dict_add2(t_str_dict **node, char *key, char *value)
{
	t_str_dict	*sd;

	sd = get_str_dict_by_key(*node, key);
	if (sd == NULL)
	{
		str_dict_push(node, ft_strdup(key), ft_strdup(value));
		return (1);
	}
	else
	{
		free(sd->value);
		sd->value = ft_strdup(value);
		return (0);
	}
}
