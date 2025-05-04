/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   void_list_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:42:48 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:56:46 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

int	void_list_clear(t_void_list **node, void (*f)(t_anytype))
{
	t_void_list	*tmp;

	while (*node != NULL)
	{
		tmp = (*node)->next;
		f((*node)->ptr);
		free(*node);
		*node = tmp;
	}
	return (0);
}

int	void_list_clear_func(\
	t_void_list **node, \
	void (*func)(t_anytype, void (*g)(void *)), \
	void (*f)(void *)
)
{
	t_void_list	*tmp;

	while (*node != NULL)
	{
		tmp = (*node)->next;
		func((*node)->ptr, f);
		free(*node);
		*node = tmp;
	}
	return (0);
}
