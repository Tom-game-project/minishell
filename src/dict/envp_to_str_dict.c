/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_to_str_dict.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:28:21 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/12 19:28:33 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "envtools.h"
#include <stdio.h>
#include <stdlib.h>

///
///
/// # TODO
///
int	envp_to_str_dict(t_str_dict **node, char *envp[])
{
	char	*str;

	while (*envp != NULL)
	{
		str = get_key_from_envp_ptr(*envp);
		if (str_dict_add(node, str, get_value_from_envp_ptr(*envp), free) == 0)
			free(str);
		envp++;
	}
	return (0);
}
