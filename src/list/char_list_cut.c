/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_list_cut.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 18:20:55 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/22 18:21:00 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_str_list	*char_list_cut(t_char_list **node, int index)
{
	return (void_list_cut(node, index));
}
