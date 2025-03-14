/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_dict_remove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:32:42 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/12 19:36:26 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include <stdlib.h>
#include "strtools.h"

/// 与えられた`key`の要素を削除する
///
int	str_dict_remove(
	t_str_dict **node, \
	char *key, void (*key_free)(void *), \
	void (*value_free)(void *))
{
	t_str_dict	*pnode;
	t_str_dict	*cur_node;

	pnode = NULL;
	cur_node = *node;
	while (cur_node != NULL)
	{
		if (ft_streq((cur_node)->key, key))
		{
			key_free(cur_node->key);
			value_free(cur_node->value);
			if (pnode == NULL)
				*node = cur_node->next;
			else
				pnode->next = cur_node->next;
			free(cur_node);
			return (0);
		}
		pnode = cur_node;
		cur_node = cur_node->next;
	}
	return (0);
}
