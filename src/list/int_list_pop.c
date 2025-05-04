/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_list_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:22:12 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:22:46 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/// - err(-1)
///
int	int_list_pop(t_int_list **node, int index)
{
	t_anytype	rvalue;
	int			err;

	err = void_list_pop(node, index, &rvalue);
	if (err == -1)
		return (-1);
	else
		return (rvalue.i32);
}
