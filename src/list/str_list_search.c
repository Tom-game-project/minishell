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

static bool	strip_string(t_anytype elem, bool (*f)(void *))
{
	return (f(elem.str));
}

char	*str_list_search(t_str_list *node, bool (*f)(char *))
{
	t_anytype	elem;

	if (void_list_search(
			node,
			strip_string,
			(t_v2bfunc) f,
			&elem
		) == -1)
		return (NULL);
	return (elem.str);
}

int	str_list_search_index(t_str_list *node, bool (*f)(char *))
{
	return (
		void_list_search_index(
			node, \
			strip_string, \
			(t_v2bfunc) f \
		)
	);
}

int	str_list_search_index_r(t_str_list *node, bool (*f)(char *))
{
	return (
		void_list_search_index_r(
			node, \
			strip_string, \
			(t_v2bfunc) f \
		)
	);
}
