/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb2_any.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:12:46 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/01 20:52:41 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "list.h"

static bool	slice_comb2_any(
	t_char_list *lst,
	t_str_list *rule_lst,
	bool (*f)(t_char_list *str_lst, t_str_list *rule_list),
	int j
)
{
	bool		b;
	t_str_list	*tmp;

	tmp = char_list_cut(&lst, j);
	b = f(tmp, rule_lst);
	void_list_concat(&tmp, lst);
	return (b);
}

bool	comb2_any(
	t_char_list *lst,
	t_str_list *rule_lst,
	bool (*f)(t_char_list *str_lst, t_str_list *rule_list)
)
{
	int	len;
	int	i;
	int	j;

	len = char_list_len(lst);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < char_list_len(lst))
		{
			if (slice_comb2_any(lst, rule_lst, f, j))
				return (true);
			j += 1;
		}
		lst = lst->next;
		i += 1;
	}
	return (false);
}
