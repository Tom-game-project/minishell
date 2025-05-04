/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_list_to_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:19:39 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:19:53 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

char	*char_list_to_str(t_char_list *node)
{
	char	*rstr;
	char	*rstr_tmp;

	rstr = (char *) malloc(sizeof(char) * char_list_len(node) + 1);
	rstr_tmp = rstr;
	if (rstr == NULL)
		return (NULL);
	while (node != NULL)
	{
		*rstr = node->ptr.c;
		node = node->next;
		rstr++;
	}
	*rstr = '\0';
	return (rstr_tmp);
}
