/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_list_get_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:15:52 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:52:53 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"

/**
 * private get_back
 * @brief free: not required
 */
t_char_list	*char_list_get_back(t_char_list *node)
{
	if (node == NULL)
		return (node);
	while (node -> next != NULL)
		node = node->next;
	return (node);
}
