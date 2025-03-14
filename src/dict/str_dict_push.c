/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_dict_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:32:10 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/12 19:32:34 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "str_dict.h"
#include <stdlib.h>
#include <stdio.h>

/// すでにkeyがあるかどうかを確認せずに追加する
int	str_dict_push(t_str_dict **node, char *key, char *value)
{
	t_str_dict	*back_node_p;
	t_str_dict	*new_node_p;

	new_node_p = str_dict_set(key, value);
	if (new_node_p == NULL)
		return (1);
	back_node_p = str_dict_get_back(*node);
	if (back_node_p == NULL)
	{
		*node = new_node_p;
		return (0);
	}
	back_node_p->next = new_node_p;
	return (0);
}

