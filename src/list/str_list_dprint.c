/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_list_dprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:26:15 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:26:36 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdio.h>

#include <stdlib.h>

/// 出力先を指定できる
int	str_list_dprint(int fd, t_str_list *node)
{
	int	i;

	i = 0;
	while (node != NULL)
	{
		dprintf(fd, "[%d] \"%s\"\n", i, node->ptr.str);
		node = node->next;
		i += 1;
	}
	return (0);
}
