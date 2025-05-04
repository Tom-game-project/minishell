/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_list_get_ptr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:16:25 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:16:31 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_char_list	*char_list_get_ptr(t_char_list *head, int index)
{
	return (void_list_get_elem(head, index));
}
