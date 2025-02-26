/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_list_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:31:18 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:31:29 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

/// もし、このリストに領域を確保した文字列を使ってる場合は
/// ここで返されたポインタでfreeをしたほうが良い
char	*str_list_pop(t_str_list **node, int index)
{
	t_anytype	rvalue;
	int			err;

	err = void_list_pop(node, index, &rvalue);
	if (err == -1)
		return (NULL);
	else
		return (rvalue.str);
}
