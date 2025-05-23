/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:19:23 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/21 18:19:24 by tmuranak         ###   ########.fr       */
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

static void	free_token_list(t_anytype elem)
{
	free(elem.ex_token->str);
	free(elem.ex_token);
}

t_void_list	*heredoc_expand_string2list(char *str, t_str_dict *env_dicts)
{
	t_char_list	*path_group;
	t_char_list	*str_group;
	t_void_list	*rlist;

	str_group = NULL;
	path_group = NULL;
	rlist = NULL;
	while (*str != '\0')
	{
		anchor_heredoc_proc(*str, &(t_list_args){&rlist, &path_group,
			&str_group}, env_dicts);
		str++;
	}
	push_expand_env(&(t_list_args){&rlist, &path_group, &str_group}, env_dicts);
	push_str_group2(&(t_list_args){&rlist, &path_group, &str_group}, e_word);
	return (rlist);
}

char	*heredoc_expand_string(char *str, t_str_dict *env_dicts)
{
	t_str_list	*lst;
	char		*rstr;

	lst = heredoc_expand_string2list(str, env_dicts);
	rstr = token_list_join(lst);
	void_list_clear(&lst, free_token_list);
	return (rstr);
}
