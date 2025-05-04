/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_dict_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:31:55 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/12 19:32:00 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "test_tools.h"

int	str_dict_print(t_str_dict *node)
{
	while (node != NULL)
	{
		debug_dprintf(STDERR_FILENO, "%s=%s\n", node->key, node->value);
		node = node->next;
	}
	return (0);
}
