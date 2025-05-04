/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_dict_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:28:57 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/12 19:29:23 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	str_dict_clear(t_str_dict **node, \
	void (*key_free)(void *), \
	void (*value_free)(void *)
)
{
	t_str_dict	*p;
	t_str_dict	*pn;

	p = *node;
	while (p != NULL)
	{
		key_free(p->key);
		value_free(p->value);
		pn = p;
		p = p->next;
		free(pn);
	}
	*node = NULL;
	return (0);
}
