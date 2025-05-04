/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   void_list_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:20:57 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/30 20:20:59 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "test_tools.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// merge sort

static t_void_list	*pop_head_element(t_void_list **node)
{
	t_void_list	*next;
	t_void_list	*tmp;

	if (*node == NULL)
	{
		return (NULL);
	}
	tmp = *node;
	next = (*node)->next;
	*node = next;
	tmp->next = NULL;
	return (tmp);
}

static t_void_list	*cmppop(t_void_list **a, t_void_list **b,
		bool (*cmp)(t_anytype, t_anytype))
{
	t_void_list	*a_head;
	t_void_list	*b_head;

	a_head = *a;
	b_head = *b;
	if (a_head == NULL)
		return (pop_head_element(b));
	if (b_head == NULL)
		return (pop_head_element(a));
	if (cmp(a_head->ptr, b_head->ptr))
		return (pop_head_element(a));
	else
		return (pop_head_element(b));
}

static int	merge_lists(t_void_list **node, t_void_list *node1,
		t_void_list *node2, bool (*cmp)(t_anytype, t_anytype))
{
	t_void_list	*p;
	t_void_list	*tail_node;

	tail_node = NULL;
	while (1)
	{
		p = cmppop(&node1, &node2, cmp);
		if (p == NULL)
			break ;
		if (tail_node == NULL)
		{
			tail_node = p;
			*node = tail_node;
		}
		else
		{
			tail_node->next = p;
			tail_node = p;
		}
	}
	return (0);
}

/// WARN
///
int	merge_sort(t_void_list **node, bool (*cmp)(t_anytype, t_anytype))
{
	t_void_list	*node1;
	t_void_list	*node2;
	int			len;

	len = void_list_len(*node);
	if (len < 2)
		return (0);
	else if (len == 2)
		node1 = void_list_cut(node, 0);
	else
		node1 = void_list_cut(node, len / 2);
	node2 = *node;
	merge_sort(&node1, cmp);
	merge_sort(&node2, cmp);
	merge_lists(node, node1, node2, cmp);
	return (0);
}
