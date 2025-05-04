/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_list_join.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:27:59 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:56:18 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "list.h"
#include "str_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "str_list.h"

static char	*unsafe_copy_string(char **target, char *str)
{
	while (*str != '\0')
	{
		**target = *str;
		str++;
		(*target)++;
	}
	return (*target);
}

/// 
/// ```
/// t_str_list *node: List["word1", "word2", "word3"]
/// char *sep       : "(^_^)"
/// -----------------------------------------------
/// return char *:"word1(^_^)word2(^_^)word3"
/// ```
char	*str_list_join(t_str_list *node, char *sep)
{
	char	*str;
	char	*str_tmp;

	str = (char *) malloc(\
		sizeof(char) * (\
		str_list_len_sum(node) + \
		(str_list_len(node) - 1) * ft_strlen(sep) \
		+ 1));
	str_tmp = str;
	while (node != NULL)
	{
		if (node->ptr.str == NULL)
		{
		}
		else
		{
			str = unsafe_copy_string(&str, node->ptr.str);
			if (node->next != NULL)
				str = unsafe_copy_string(&str, sep);
		}
		node = node->next;
	}
	*str = '\0';
	return (str_tmp);
}
