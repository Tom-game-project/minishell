/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_expand_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:10:36 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/03 18:51:52 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "libft.h"
#include "list.h"
#include "private.h"
#include <stdbool.h>
#include <stdio.h>

///
///
///

///
int	push_expand_env(t_list_args *group_args, t_str_dict *dict)
{
	t_str_dict	*r;
	char		*str;

	if (!char_list_is_empty(*group_args->path_group))
	{
		char_list_pop(group_args->path_group, 0);
		str = char_list_to_str(*group_args->path_group);
		r = get_str_dict_by_key(dict, str);
		free(str);
		if (r == NULL)
		{
		}
		else
		{
			void_list_push(group_args->rlist, alloc_ex_token(e_word,
					ft_strdup(r->value)));
		}
		char_list_clear(group_args->path_group);
	}
	return (0);
}
