/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_list_search.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:32:20 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:54:07 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>
#include <stdbool.h>
#include "void_list.h"

static bool	strip_string2(t_anytype elem, bool (*f)(void *, void *), void *str)
{
	return (f(elem.str, str));
}

///
t_str_list	*str_list_search_node(
	t_str_list *node, \
	bool (*f)(char *, char *), \
	char *str
)
{
	int	index;

	index = void_list_search2_index(\
		node, \
		strip_string2, \
		(t_vv2bfunc) f, \
		(void *) str \
	);
	if (index == -1)
		return (NULL);
	return (void_list_get_elem(node, index));
}
