/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   void_list_pop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:47:21 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:47:28 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "str_list.h"
#include <stdlib.h>

/**
 * pub pop_elem
 * @brief free:required
 * @param node_p_p
 */
static t_void_list	*pop_elem(t_void_list **node_p_p)
{
	t_void_list	*head_p;

	head_p = *node_p_p;
	if (head_p == NULL)
		return (NULL);
	*node_p_p = head_p->next;
	if (head_p -> next != NULL)
	{
		head_p->next = NULL;
	}
	return (head_p);
}

/// @brief you must free returned object by yourself
///        values outside the range are undefined
/// @param node_p_p
/// @param index
/// @return
static t_void_list	*pop_index_elem(t_void_list **node_p_p, int index)
{
	t_void_list	*r_node;
	t_void_list	*pre_node;

	if (index == 0)
		return (pop_elem(node_p_p));
	r_node = str_list_get_ptr(*node_p_p, index);
	pre_node = str_list_get_ptr(*node_p_p, index - 1);
	pre_node->next = r_node->next;
	r_node->next = NULL;
	return (r_node);
}

///
int	void_list_pop(t_void_list **node, int index, t_anytype *rvalue)
{
	t_void_list	*head_p;

	if (index < 0 && void_list_len(*node) <= index)
		return (-1);
	head_p = pop_index_elem(node, index);
	if (head_p == NULL)
		return (-1);
	*rvalue = head_p->ptr;
	free(head_p);
	return (0);
}
