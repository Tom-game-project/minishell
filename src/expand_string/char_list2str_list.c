/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_list2str_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:39:08 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/04 15:39:09 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "expand_string.h"
#include "list.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

static bool	is_newline_wrapper(char *s)
{
	return (*s == '\n');
}

static char	*replace_expaded_env(char *str, t_str_dict *env_dict)
{
	char	*rstr;

	rstr = heredoc_expand_string(str, env_dict);
	free(str);
	return (rstr);
}

/// `t_char_list`を文字列としてみて環境変数を展開し
/// その結果を`t_str_list`として返す関数
t_str_list	*char_list2str_list(t_char_list **lst, t_str_dict *env_dict)
{
	char		*str;
	t_str_list	*expanded;
	int			index;
	t_char_list	*b;

	expanded = NULL;
	while (1)
	{
		index = char_list_search_index(*lst, is_newline_wrapper);
		if (index == -1)
			break ;
		b = char_list_cut(lst, index);
		str = char_list_to_str(b);
		char_list_clear(&b);
		str_list_push(&expanded, replace_expaded_env(str, env_dict));
	}
	if (char_list_len(*lst) != 0)
	{
		str = char_list_to_str(*lst);
		str_list_push(&expanded, str);
	}
	return (expanded);
}
