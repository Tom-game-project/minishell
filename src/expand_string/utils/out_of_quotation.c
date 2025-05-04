/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_of_quotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:51:22 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/03 18:51:24 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// out of quotation
#include "dict.h"
#include "envtools.h"
#include "libft.h"
#include "list.h"
#include "private.h"
#include <unistd.h>

static t_anchor	single_quotation_proc(char c, t_list_args *group_args,
		t_str_dict *env_dicts)
{
	(void)c;
	push_expand_env(group_args, env_dicts);
	push_str_group2(group_args, e_word);
	return (e_anchor_q);
}

static t_anchor	double_quotation_proc(char c, t_list_args *group_args,
		t_str_dict *env_dicts)
{
	(void)c;
	push_expand_env(group_args, env_dicts);
	push_str_group2(group_args, e_word);
	return (e_anchor_dq);
}

static void	anchor_out_proc_helper(char c, t_list_args *group_args,
		t_str_dict *env_dicts)
{
	if (!char_list_is_empty(*group_args->path_group))
	{
		if (is_valid_env_char(c))
			char_list_push(group_args->path_group, c);
		else
		{
			push_expand_env(group_args, env_dicts);
			push_str_group2(group_args, e_word);
			char_list_push(group_args->str_group, c);
		}
	}
	else
		char_list_push(group_args->str_group, c);
}

t_anchor	anchor_out_proc(char c, t_list_args *group_args,
		t_str_dict *env_dicts)
{
	if (c == '\'')
		return (single_quotation_proc(c, group_args, env_dicts));
	else if (c == '"')
		return (double_quotation_proc(c, group_args, env_dicts));
	else if (c == '$')
		return (dollar_proc(c, group_args, env_dicts));
	else if (c == '?')
		return (question_proc(c, group_args, env_dicts));
	else if (c == '*')
	{
		push_str_group2(group_args, e_word);
		void_list_push(group_args->rlist, alloc_ex_token(e_asterisk,
				ft_strdup("*")));
	}
	else
		anchor_out_proc_helper(c, group_args, env_dicts);
	return (e_anchor_out);
}
