/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   void_list_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:47:42 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:47:51 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

int	void_list_print(t_void_list *node, int (*print)(int, t_anytype))
{
	int	i;

	i = 0;
	while (node != NULL)
	{
		print(i, node->ptr);
		node = node->next;
		i += 1;
	}
	return (0);
}
