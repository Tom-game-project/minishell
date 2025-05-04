/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   void_list_filter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:25:50 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/30 20:25:50 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

///
///
t_void_list	*void_list_filter(t_void_list **node, bool (*f)(t_anytype))
{
	t_void_list	*t_list;
	t_void_list	*f_list;
	t_void_list	*tmp;
	t_void_list	*p;

	p = *node;
	t_list = NULL;
	f_list = NULL;
	while (p != NULL)
	{
		tmp = p;
		p = p->next;
		if (f(tmp->ptr))
		{
			tmp->next = NULL;
			void_list_concat(&t_list, tmp);
		}
		else
		{
			tmp->next = NULL;
			void_list_concat(&f_list, tmp);
		}
	}
	*node = f_list;
	return (t_list);
}

///
t_void_list	*void_list_filter2(t_void_list **node, bool (*f)(t_anytype,
			t_anytype), t_anytype arg)
{
	t_void_list	*t_list;
	t_void_list	*f_list;
	t_void_list	*tmp;
	t_void_list	*p;

	p = *node;
	t_list = NULL;
	f_list = NULL;
	while (p != NULL)
	{
		tmp = p;
		p = p->next;
		if (f(tmp->ptr, arg))
		{
			tmp->next = NULL;
			void_list_concat(&t_list, tmp);
		}
		else
		{
			tmp->next = NULL;
			void_list_concat(&f_list, tmp);
		}
	}
	*node = f_list;
	return (t_list);
}
