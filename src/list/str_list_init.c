/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_list_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:27:38 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:27:50 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

/**
 * pub init_char_list
 * @brief free: required
 *
 */
t_str_list	*init_str_list(char *str)
{
	t_anytype	elem;

	elem.str = str;
	return (void_list_init(elem));
}
