/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_ifs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 21:29:38 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/21 21:30:09 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

static void	nop(void *a)
{
	(void) a;
}

int	remove_ifs(t_str_list **lst)
{
	t_str_list	*ifs_lst;

	if (str_list_len(*lst) == 0)
		return (1);
	ifs_lst = NULL;
	str_list_push(&ifs_lst, " ");
	str_list_push(&ifs_lst, "\t");
	str_list_push(&ifs_lst, "\n");
	str_list_trim(lst, ifs_lst, free);
	str_list_clear(&ifs_lst, nop);
	return (0);
}

