/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_dict_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:36:35 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/30 19:58:15 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include <stdlib.h>

t_str_dict	*str_dict_set(char *key, char *value)
{
	t_str_dict	*node;

	node = init_str_dict();
	if (node == NULL)
		return (NULL);
	node->key = key;
	node->value = value;
	return (node);
}
