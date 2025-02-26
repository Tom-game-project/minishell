/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_list_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:20:49 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:21:00 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static void	nop(t_anytype a)
{
	(void) a;
}

/// clear
///
int	int_list_clear(t_int_list **node)
{
	return (void_list_clear(node, nop));
}
