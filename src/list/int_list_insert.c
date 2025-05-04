/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_list_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:21:35 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:21:44 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	int_list_insert(t_int_list **node, int index, int i)
{
	t_anytype	elem;

	elem.i32 = i;
	return (void_list_insert(node, index, elem));
}
