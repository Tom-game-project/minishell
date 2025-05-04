/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_dict_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:30:02 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/12 19:30:28 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include <stdlib.h>

t_str_dict	*init_str_dict(void)
{
	t_str_dict	*node;

	node = (t_str_dict *)malloc(sizeof(t_str_dict));
	if (node == NULL)
		return (NULL);
	node->next = NULL;
	node->key = NULL;
	node->value = NULL;
	return (node);
}
