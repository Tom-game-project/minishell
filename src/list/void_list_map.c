/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   void_list_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:46:28 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:54:49 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

///
int	void_list_map(
		t_void_list **node, \
		t_anytype (*func)(t_anytype, void *(*g)(void *)),
		void *(*f)(void *)
)
{
	t_void_list	*p;

	p = *node;
	while (p != NULL)
	{
		p->ptr = func(p->ptr, f);
		p = p->next;
	}
	return (0);
}

int	void_list_map_arg1(
		t_void_list **node, \
		t_anytype (*func)(t_anytype, void *(*g)(void *, void *), void *),
		void *(*f)(void *, void *), \
		void *arg
)
{
	t_void_list	*p;

	p = *node;
	while (p != NULL)
	{
		p->ptr = func(p->ptr, f, arg);
		p = p->next;
	}
	return (0);
}
