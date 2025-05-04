/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   void_list_insert_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:17:58 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/30 20:18:24 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

///
int	void_list_insert_list(
	t_void_list **target,
	t_void_list *lst,
	int index
)
{
	t_void_list	*head;

	head = void_list_cut(target, index);
	if (head == NULL)
		head = lst;
	else
		void_list_concat(&head, lst);
	if (lst != NULL)
		void_list_concat(&lst, *target);
	*target = head;
	return (0);
}
