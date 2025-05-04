/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_dict_get_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:29:34 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/12 19:29:48 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include <stdlib.h>

t_str_dict	*str_dict_get_back(t_str_dict *node)
{
	if (node == NULL)
		return (node);
	while (node->next != NULL)
		node = node->next;
	return (node);
}
