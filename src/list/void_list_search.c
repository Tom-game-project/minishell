/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   void_list_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:48:09 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:55:19 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdbool.h>
#include <stdlib.h>

///
/// - err(-1)
/// - ok(0)
int	void_list_search(t_void_list *node, bool (*func)(t_anytype,
			bool (*g)(void *)), bool (*f)(void *), t_anytype *rvalue)
{
	while (node != NULL)
	{
		if (func(node->ptr, f))
		{
			*rvalue = node->ptr;
			return (0);
		}
		node = node->next;
	}
	return (-1);
}

///
/// - not found (-1)
/// - index(n >= 0)
int	void_list_search_index(t_void_list *node, bool (*func)(t_anytype,
			bool (*g)(void *)), bool (*f)(void *))
{
	int	i;

	i = 0;
	while (node != NULL)
	{
		if (func(node->ptr, f))
			return (i);
		node = node->next;
		i += 1;
	}
	return (-1);
}

///
/// - not found (-1)
/// - index(n >= 0)
int	void_list_search_index_r(t_void_list *node, bool (*func)(t_anytype,
			bool (*g)(void *)), bool (*f)(void *))
{
	int	i;
	int	rindex;

	i = 0;
	rindex = -1;
	while (node != NULL)
	{
		if (func(node->ptr, f))
			rindex = i;
		node = node->next;
		i += 1;
	}
	return (rindex);
}

///
///
/// - not found (-1)
/// - index(n >= 0)
int	void_list_search2_index(t_void_list *node, bool (*func)(t_anytype,
			bool (*g)(void *, void *), void *), bool (*f)(void *, void *),
		void *str)
{
	int	i;

	i = 0;
	while (node != NULL)
	{
		if (func(node->ptr, f, str))
			return (i);
		node = node->next;
		i += 1;
	}
	return (-1);
}
