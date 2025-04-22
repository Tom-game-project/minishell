/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_double_quotation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:23:48 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/12 20:25:15 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "dict.h"
#include "envtools.h"
#include "private.h"

t_anchor	anchor_dq_proc(\
	char c, \
	t_list_args *group_args, \
	t_str_dict *env_dicts)
{
	if (c == '"')
	{
		push_expand_env(group_args, env_dicts);
		push_str_group2(group_args, e_word);
		return (e_anchor_out);
	}
	else if (c == '$')
	{
		push_expand_env(group_args, env_dicts);
		push_str_group2(group_args, e_word);
		char_list_push(group_args->path_group, c);
	}
	else
		if (!char_list_is_empty(*group_args->path_group))
			if (is_valid_env_char(c))
				char_list_push(group_args->path_group, c);
			else
			{
				push_expand_env(group_args, env_dicts);
				push_str_group2(group_args, e_word);
				char_list_push(group_args->str_group, c);
			}
		else
			char_list_push(group_args->str_group, c);
	return (e_anchor_dq);
}

