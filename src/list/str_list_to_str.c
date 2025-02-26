/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_list_to_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:41:31 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:41:43 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>
#include "str_list.h"

char	*str_list_to_str(t_str_list *node)
{
	char	*rstr;
	char	*rstr_tmp;
	char	*i_str;

	rstr = (char *)malloc(sizeof(char) * (str_list_len_sum(node) + 1));
	if (rstr == NULL)
		return (NULL);
	rstr_tmp = rstr;
	while (node != NULL)
	{
		i_str = node->ptr.str;
		while (*i_str != '\0')
		{
			*rstr = *i_str;
			rstr++;
			i_str++;
		}
		node = node->next;
	}
	*rstr = '\0';
	return (rstr_tmp);
}
