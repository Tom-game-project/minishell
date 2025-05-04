/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_list_get_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:26:57 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:27:07 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

char	*str_list_get_elem(t_str_list *node, int index)
{
	t_void_list	*p;

	p = void_list_get_elem(node, index);
	if (p == NULL)
		return (NULL);
	return (p->ptr.str);
}
