/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   void_list_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:45:37 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:45:50 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

t_void_list	*void_list_init(t_anytype ptr)
{
	t_void_list	*node;

	node = (t_void_list *) malloc(sizeof(t_void_list));
	if (node == NULL)
		return (NULL);
	node->ptr = ptr;
	node->next = NULL;
	return (node);
}
