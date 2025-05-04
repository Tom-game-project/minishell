/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   void_list_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:46:15 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:46:23 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

int	void_list_len(t_void_list *node)
{
	int	i;

	i = 0;
	while (node != NULL)
	{
		i += 1;
		node = node->next;
	}
	return (i);
}
