/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_list_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:24:22 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:55:41 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static void	strip_anytype(t_anytype elem, void (*f)(void *))
{
	f(elem.str);
}

int	str_list_clear(t_str_list **node, void (*f)(void *))
{
	return (void_list_clear_func(node, strip_anytype, f));
}
