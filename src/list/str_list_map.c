/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_list_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:29:54 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:31:10 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "void_list.h"

static
t_anytype	strip_str_list_func(t_anytype elem, void *(*f)(void *))
{
	t_anytype	e;

	e.str = f(elem.str);
	return (e);
}

int	str_list_map(t_str_list **node, char *(*f)(char *))
{
	return (
		void_list_map(
			node,
			strip_str_list_func,
			(t_v2vfunc)f
		)
	);
}

static t_anytype	strip_str_list_func2(
	t_anytype elem, \
	void *(*f)(void *, void *), \
	void *str
)
{
	t_anytype	e;

	e.str = f(elem.str, str);
	return (e);
}

int	str_list_map_arg1(
	t_str_list **node, \
	char *(*f)(char *, void *), \
	void *arg
)
{
	return (
		void_list_map_arg1(
			node,
			strip_str_list_func2,
			(t_vv2vfunc) f,
			arg
		)
	);
}
