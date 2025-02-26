/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_list_get_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:26:45 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:53:52 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

t_str_list	*str_list_get_back(t_str_list *node)
{
	if (node == NULL)
		return (node);
	while (node -> next != NULL)
		node = node->next;
	return (node);
}
