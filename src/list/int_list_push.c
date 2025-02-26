/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_list_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:23:48 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:23:56 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	int_list_push(t_int_list **node, int i)
{
	t_anytype	elem;

	elem.i32 = i;
	void_list_push(node, elem);
	return (0);
}
