/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_list_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:15:26 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:15:36 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static void	nop(t_anytype elem)
{
	(void) elem;
}

int	char_list_clear(t_char_list **node)
{
	return (void_list_clear(node, nop));
}
