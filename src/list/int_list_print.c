/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_list_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:23:07 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:23:40 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "test_tools.h"
#include <unistd.h>

static int	print_int(int index, t_anytype elem)
{
	debug_dprintf(STDERR_FILENO, "[%d] [%d]\n", index, elem.i32);
	return (0);
}

int	int_list_print(t_int_list *node)
{
	return (void_list_print(node, print_int));
}
