/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:16:13 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/12 20:23:33 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// out of quotation
#include "list.h"
#include "dict.h"
#include "private.h"
#include "envtools.h"

/// クォーテーション外の処理
t_anchor	anchor_heredoc_proc(\
	char c, \
	t_list_args *group_args, \
	t_str_dict *env_dicts)
{
	if (c == '$')
		return (dollar_proc(c, group_args, env_dicts));
	else if (c == '?')
		return (question_proc(c, group_args, env_dicts));
	else
	{
		if (!char_list_is_empty(*group_args->path_group))
		{
			if (is_valid_env_char(c))
				char_list_push(group_args->path_group, c);
			else
			{
				push_expand_env(group_args, env_dicts);
				push_str_group(group_args);
				char_list_push(group_args->str_group, c);
			}
		}
		else
			char_list_push(group_args->str_group, c);
	}
	return (e_anchor_out);
}

