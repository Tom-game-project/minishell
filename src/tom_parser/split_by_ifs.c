/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_ifs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 21:30:16 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/01 19:09:08 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "tom_parser.h"
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

static bool	is_ifs(char *c)
{
	return (*c == ' ' || *c == '\t' || *c == '\n');
}

/// true -> break
/// false -> continue
static bool	update_new_list_split_by_ifs(t_str_list **lst, t_str_list **new_lst,
		void (*f)(void *))
{
	int			index;
	t_str_list	*tmp;

	index = str_list_search_index(*lst, is_ifs);
	if (index == -1)
	{
		str_list_push(new_lst, str_list_to_str(*lst));
		str_list_clear(lst, f);
		return (true);
	}
	else
	{
		tmp = str_list_cut(lst, index - 1);
		f(str_list_pop(lst, 0));
		str_list_push(new_lst, str_list_to_str(tmp));
		str_list_clear(&tmp, f);
		return (false);
	}
}

///
/// ```
/// [] [" "] []
/// ```
int	split_by_ifs(t_str_list **lst, void (*f)(void *))
{
	t_str_list	*new_lst;

	new_lst = NULL;
	if (str_list_len(*lst) == 0)
		return (0);
	while (1)
	{
		if (update_new_list_split_by_ifs(lst, &new_lst, f))
			break ;
	}
	str_list_clear(lst, f);
	*lst = new_lst;
	return (0);
}
