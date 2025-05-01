/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_list_trim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:27:56 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/30 20:28:33 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	str_list_trim(t_str_list **lst, t_str_list *set, void (*f)(void *))
{
	int			point_index;
	t_str_list	*tmp;

	point_index = str_list_len(*lst) - 1;
	while (str_list_in(str_list_get_elem(*lst, point_index), set))
	{
		point_index -= 1;
		if (point_index < 0)
			return (str_list_clear(lst, f), 0);
	}
	tmp = *lst;
	*lst = str_list_cut(&tmp, point_index);
	str_list_clear(&tmp, f);
	point_index = -1;
	while (str_list_in(str_list_get_elem(*lst, point_index + 1), set))
	{
		point_index += 1;
		if (str_list_len(*lst) - 1 <= point_index)
			break ;
	}
	tmp = str_list_cut(lst, point_index);
	str_list_clear(&tmp, f);
	return (point_index);
}
