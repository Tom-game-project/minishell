/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_list_get_elem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:16:10 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:52:44 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

char	char_list_get_elem(t_char_list *node, int index)
{
	t_void_list	*a;

	a = void_list_get_elem(node, index);
	if (a == NULL)
		return ('\0');
	return (a->ptr.c);
}
