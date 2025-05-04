/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_dict_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:30:56 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/12 19:31:46 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include <stdlib.h>

int	str_dict_len(t_str_dict *node)
{
	int	i;

	i = 0;
	while (node != NULL)
	{
		node = node->next;
		i += 1;
	}
	return (i);
}
