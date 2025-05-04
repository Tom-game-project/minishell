/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   question_proc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:39:34 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/04 15:39:34 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "dict.h"
#include "private.h"
#include <unistd.h>

t_anchor	question_proc(
	char c, t_list_args *group_args, t_str_dict *env_dicts)
{
	if (char_list_len(*group_args->path_group) == 1)
	{
		char_list_push(group_args->path_group, c);
		push_expand_env(group_args, env_dicts);
		push_str_group2(group_args, e_word);
	}
	else if (char_list_len(*group_args->path_group) == 0)
	{
		char_list_push(group_args->str_group, c);
	}
	else
	{
		push_expand_env(group_args, env_dicts);
		char_list_push(group_args->str_group, c);
	}
	return (e_anchor_out);
}
