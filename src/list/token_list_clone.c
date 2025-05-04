/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list_clone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:18:51 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/30 20:19:14 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

t_void_list	*token_list_clone(t_void_list *lst, t_anytype (*f)(t_anytype))
{
	t_void_list	*rlst;

	rlst = NULL;
	while (lst != NULL)
	{
		void_list_push(&rlst, f(lst->ptr));
		lst = lst->next;
	}
	return (rlst);
}
