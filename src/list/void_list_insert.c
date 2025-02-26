/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   void_list_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:45:55 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:46:02 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

int	void_list_insert(t_void_list **node, int index, t_anytype elem)
{
	t_void_list	*target_node;
	t_void_list	*new_node;
	t_void_list	*start_node;

	target_node = void_list_get_elem(*node, index);
	new_node = void_list_init(elem);
	if (new_node == NULL)
		return (1);
	new_node->next = target_node;
	if (0 < index)
	{
		start_node = void_list_get_elem(*node, index - 1);
		start_node->next = new_node;
	}
	else
		*node = new_node;
	return (0);
}
