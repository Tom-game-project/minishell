/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_dict_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:30:38 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/12 19:30:51 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "strtools.h"
#include <stdlib.h>
#include <stdbool.h>
// for test
//
#include <stdio.h>
#include <unistd.h>

/// keyが見つからない場合はNULLを返却する
/// keyが見つかった場合は`t_str_dict *`を返す
t_str_dict	*get_str_dict_by_key(\
		t_str_dict *node, char *key)
{
	while (node != NULL)
	{
		if (ft_streq(node->key, key))
			return (node);
		node = node->next;
	}
	return (NULL);
}
