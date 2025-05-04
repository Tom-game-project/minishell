/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_list_all_concat.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:29:36 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/30 20:29:36 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

/// ```
/// Vec<Vec<elem>> -> Vec<elem>
/// ```
///
/// ```
/// [
/// [a ,b, c]
/// [d, e, f]
/// ]
/// -> [a, b, c, d, e, f]
/// ```
///
///
t_void_list	*list_list_all_concat(t_void_list *list // Vec<Vec<str>>
)
{
	t_void_list	*rlist;

	rlist = NULL;
	while (list != NULL)
	{
		void_list_concat(&rlist, list->ptr.list);
		list = list->next;
	}
	return (rlist);
}
