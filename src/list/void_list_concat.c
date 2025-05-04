/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   void_list_concat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:44:07 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:44:14 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"

int	void_list_concat(t_void_list **a, t_void_list *b)
{
	t_void_list	*node;

	if (*a == NULL)
	{
		*a = b;
		return (0);
	}
	node = str_list_get_back(*a);
	node->next = b;
	return (0);
}
