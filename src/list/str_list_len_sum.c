/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_list_len_sum.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:29:31 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:29:40 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "libft.h"

#include <stdlib.h>

int	str_list_len_sum(t_str_list *node)
{
	int	i;

	i = 0;
	while (node != NULL)
	{
		if (node->ptr.str == NULL)
		{
			node = node->next;
		}
		else
		{
			i += ft_strlen(node->ptr.str);
			node = node->next;
		}
	}
	return (i);
}
