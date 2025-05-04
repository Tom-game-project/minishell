/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_list_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:21:15 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:21:24 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

///
t_int_list	*init_int_list(int i)
{
	t_anytype	elem;

	elem.i32 = i;
	return (void_list_init(elem));
}
