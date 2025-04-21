/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:25:05 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/21 18:26:17 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

static bool	is_slash(char *c)
{
	return (*c == '/');
}

/// pathを分解する関数
t_str_list	*split_path_by_slash(char *path)
{
	t_char_list	*char_lst;
	t_str_list	*str_lst;
	int			index;
	t_char_list	*group_char_lst;

	char_lst = NULL;
	str_lst = NULL;
	char_list_push_str(&char_lst, path);
	index = char_list_search_index(char_lst, is_slash);
	while (index != -1)
	{
		group_char_lst = char_list_cut(&char_lst, index);
		str_list_push(&str_lst, char_list_to_str(group_char_lst));
		index = char_list_search_index(char_lst, is_slash);
		char_list_clear(&group_char_lst);
	}
	if (char_list_len(char_lst) != 0)
	{
		str_list_push(&str_lst, char_list_to_str(char_lst));
	}
	char_list_clear(&char_lst);
	return (str_lst);
}
