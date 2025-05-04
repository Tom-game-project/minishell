/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_collector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:36:48 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/22 19:45:59 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "strtools.h"
#include <stdbool.h>
#include <stdlib.h>

static void	nop(void *a)
{
	(void)a;
}

///
/// lst1 = [0, 1, 2];
/// lst2 = [0, 1];
/// -> true
///
/// lst1 = [1];
/// lst2 = [1, 2];
/// -> false
bool	str_list_cmp(t_str_list *lst1, t_str_list *lst2)
{
	while (lst1 != NULL && lst2 != NULL)
	{
		if (!ft_streq(lst1->ptr.str, lst2->ptr.str))
			return (false);
		lst1 = lst1->next;
		lst2 = lst2->next;
	}
	return (str_list_len(lst1) >= str_list_len(lst2));
}

static void	search_string_pattern_replace_helper(t_str_list **lst,
		t_str_list *pattern, int index)
{
	int			incr;
	t_anytype	elem;
	char		*s;

	incr = 0;
	while (incr < str_list_len(pattern))
	{
		s = str_list_pop(lst, index);
		free(s);
		incr += 1;
	}
	elem.str = str_list_to_str(pattern);
	void_list_insert(lst, index, elem);
}

/// ```
/// [a] -> [b] -> [c]
/// [a] -> [b]
/// ```
/// ->
///
/// ```
/// [ab] -> [c]
/// ```
///
/// search_string_pattern_replace
int	search_string_pattern_replace(t_str_list **lst, t_str_list *pattern)
{
	t_str_list	*i;
	int			index;

	i = *lst;
	index = 0;
	while (i != NULL)
	{
		if (str_list_cmp(i, pattern))
		{
			search_string_pattern_replace_helper(lst, pattern, index);
			return (1);
		}
		i = i->next;
		index += 1;
	}
	return (0);
}

int	ope_collector(t_str_list **lexed)
{
	t_str_list	*ptn[4];
	char		*table[4];
	int			i;

	table[0] = "|";
	table[1] = ">";
	table[2] = "<";
	table[3] = "&";
	i = 0;
	while (i < 4)
	{
		ptn[i] = NULL;
		str_list_push(&ptn[i], table[i]);
		str_list_push(&ptn[i], table[i]);
		while (search_string_pattern_replace(lexed, ptn[i]) != 0)
			;
		str_list_clear(&ptn[i], nop);
		i += 1;
	}
	return (0);
}
