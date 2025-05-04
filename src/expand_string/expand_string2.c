/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_string2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:47:01 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/03 18:47:02 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// # expand_string.c
///
///
#include "dict.h"
#include "list.h"
#include "utils/private.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static t_anchor	expand_string2list2_loop_proc(t_anchor anc, char *str,
		t_list_args lst_args, t_str_dict *env_dicts)
{
	if (anc == e_anchor_out)
		return (anchor_out_proc(*str, &lst_args, env_dicts));
	else if (anc == e_anchor_q)
		return (anchor_q_proc(*str, &lst_args));
	else if (anc == e_anchor_dq)
		return (anchor_dq_proc(*str, &lst_args, env_dicts));
	return (anc);
}

///
/// example
/// ```
/// "\"  $PATH  \"\"   hello  \""
/// ```
///
/// example
/// ```
/// "\"Tom\"\"'\"\"s Home Party\""
/// return ("Tom's Home Party")
/// ```
///
/// example
/// ```
/// "$PATH"
/// ```
/// return new_string
///
t_void_list	*expand_string2list2(char *str, t_str_dict *env_dicts)
{
	t_anchor	anc;
	t_char_list	*path_group;
	t_char_list	*str_group;
	t_void_list	*rlist;
	t_list_args	lst_args;

	anc = e_anchor_out;
	str_group = NULL;
	path_group = NULL;
	rlist = NULL;
	while (*str != '\0')
	{
		lst_args = (t_list_args){&rlist, &path_group, &str_group};
		anc = expand_string2list2_loop_proc(anc, str, lst_args, env_dicts);
		str++;
	}
	lst_args = (t_list_args){&rlist, &path_group, &str_group};
	push_expand_env(&lst_args, env_dicts);
	push_str_group2(&lst_args, e_word);
	return (rlist);
}
