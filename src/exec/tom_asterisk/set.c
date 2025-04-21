/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:24:29 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/21 18:24:56 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "libft.h"
#include <stdlib.h>

static bool	is_asterisk_char(char *c)
{
	return (*c == '*');
}

t_str_list	*rule_to_lst(char *rule_str)
{
	t_char_list	*c_lst;
	t_char_list	*group;
	t_str_list	*rlst;
	int			index;

	c_lst = NULL;
	rlst = NULL;
	char_list_push_str(&c_lst, rule_str);
	index = char_list_search_index(c_lst, is_asterisk_char);
	while (index != -1)
	{
		group = char_list_cut(&c_lst, index - 1);
		if (char_list_len(group) != 0)
			str_list_push(&rlst, char_list_to_str(group));
		char_list_pop(&c_lst, 0);
		str_list_push(&rlst, ft_strdup("*"));
		char_list_clear(&group);
		index = char_list_search_index(c_lst, is_asterisk_char);
	}
	if (char_list_len(c_lst) != 0)
		str_list_push(&rlst, char_list_to_str(c_lst));
	char_list_clear(&c_lst);
	return (rlst);
}

