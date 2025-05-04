/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_list_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:18:59 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/30 20:26:41 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/** 
 * pub char_list_push
 * 
 * @brief free: required (depend on \`init_node\` function)
 * @param parent_p
 * @param i32_data 
 * @return
 */
int	char_list_push(t_char_list **node, char c)
{
	t_anytype	elem;

	elem.c = c;
	return (void_list_push(node, elem));
}

int	char_list_push_str(t_char_list **node, char *str)
{
	while (*str != '\0')
	{
		if (char_list_push(node, *str) == 1)
			return (1);
		str++;
	}
	return (0);
}
