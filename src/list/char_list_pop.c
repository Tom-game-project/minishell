/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_list_pop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:18:22 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:53:40 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

char	char_list_pop(t_char_list **node, int index)
{
	t_anytype	rvalue;
	int			err;

	err = void_list_pop(node, index, &rvalue);
	if (err == -1)
		return ('\0');
	else
		return (rvalue.c);
}
