/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   void_list_get_elem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:45:24 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:45:33 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

t_void_list	*void_list_get_elem(t_void_list *node, int index)
{
	int	i;

	i = 0;
	while (node != NULL)
	{
		if (i == index)
			return (node);
		node = node->next;
		i += 1;
	}
	return (NULL);
}
