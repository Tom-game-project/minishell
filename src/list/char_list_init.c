/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_list_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:16:43 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:16:58 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/**
 * pub init_char_list
 * @brief free: required
 *
 */
t_char_list	*init_char_list(char c)
{
	t_anytype	elem;

	elem.c = c;
	return (void_list_init(elem));
}
