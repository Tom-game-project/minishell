/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_list_to_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:41:08 by tmuranak          #+#    #+#             */
/*   Updated: 2025/02/26 17:41:21 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>
#include "libft.h"

///
static void	clear_string_array(char **arr)
{
	while (*arr == NULL)
	{
		free(*arr);
		arr++;
	}
}

///
/// list["word0", "word1", "word2", ...]
/// 
///
/// array["word0", "word1", "word2", ..., NULL]
///
/// ```c
/// return ["allocated string", "allocated string", NULL];
/// ```
char	**str_list_to_array(t_str_list *node)
{
	char	**array_str;
	char	**array_str_tmp;

	array_str = (char **)malloc(\
	sizeof(char *) * (str_list_len(node) + 1));
	if (array_str == NULL)
		return (NULL);
	array_str_tmp = array_str;
	while (node != NULL)
	{
		*array_str = ft_strdup(node->ptr.str);
		if (*array_str == NULL)
		{
			clear_string_array(array_str_tmp);
			free(array_str_tmp);
			return (NULL);
		}
		node = node->next;
		array_str++;
	}
	*array_str = NULL;
	return (array_str_tmp);
}
