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

/// 二次元リストの次元を落とす関数
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
/// この関数の引数に通した関数の所有権は引数で返されるリストに完全に譲渡されます
///
/// この関数を呼び出すプログラマは、渡した関数を開放する義務がある
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
