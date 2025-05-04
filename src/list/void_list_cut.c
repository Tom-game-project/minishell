/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   void_list_cut.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:44:29 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:45:04 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

///
/// def 
/// &lst = 
/// [0] -> [1] -> [2] -> [3] -> ...
///
/// &lst
/// index = 2
///
/// &lst = [3] -> ...
///
/// return [0] -> [1] -> [2] -> NULL
t_void_list	*void_list_cut(t_void_list **node, int index)
{
	int			i;
	t_void_list	*p;
	t_void_list	*tmp;

	i = 0;
	if (void_list_len(*node) <= index)
		index = void_list_len(*node) - 1;
	if (index < 0)
		return (NULL);
	p = *node;
	while (p != NULL)
	{
		if (i == index)
		{
			tmp = *node;
			*node = p->next;
			p->next = NULL;
			return (tmp);
		}
		i += 1;
		p = p->next;
	}
	return (*node);
}
