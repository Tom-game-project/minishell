/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_list_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:18:41 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:18:51 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdio.h>

int	print_char(int index, t_anytype elem)
{
	printf("[%d] [%c]\n", index, elem.c);
	return (0);
}

int	char_list_print(t_char_list *node)
{
	return (void_list_print(node, print_char));
}
