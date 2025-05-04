/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:39:03 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/02 18:56:50 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "list.h"
#include "tom_asterisk.h"
#include <stdlib.h>

static t_anytype	copy_token_list_node(t_anytype elem)
{
	return (alloc_ex_token(elem.ex_token->token_type,
			ft_strdup(elem.ex_token->str)));
}

static char	*remove_slash(char *str)
{
	if (str[ft_strlen(str) - 1] == '/')
		return (ft_substr(str, 0, ft_strlen(str) - 1));
	else
		return (ft_strdup(str));
}

static t_void_list	*remove_slash_from_rule_list(t_void_list *lst)
{
	t_void_list	*rlist;
	t_void_list	*last_elem;
	t_anytype	elem;
	char		*str;

	rlist = token_list_clone(lst, copy_token_list_node);
	last_elem = void_list_get_elem(rlist, void_list_len(lst) - 1);
	str = last_elem->ptr.ex_token->str;
	if (str[ft_strlen(str) - 1] == '/')
	{
		void_list_pop(&rlist, void_list_len(lst) - 1, &elem);
		void_list_push(&rlist, alloc_ex_token(e_word,
				remove_slash(elem.ex_token->str)));
		free_ex_token(elem);
	}
	return (rlist);
}

static bool	func_wrap(t_anytype a, t_anytype b)
{
	t_char_list	*c_lst;
	t_str_list	*rule_lst;
	bool		r;

	c_lst = NULL;
	char_list_push_str(&c_lst, a.str);
	rule_lst = b.list;
	r = is_same_string(c_lst, rule_lst);
	char_list_clear(&c_lst);
	return (r);
}

t_str_list	*filter_paths_by_rule_wrap(t_str_list **curr_lst,
		t_void_list *rule_list)
{
	t_str_list	*filtered;
	t_void_list	*slash_removed_str;
	t_anytype	rule_str_anytype;

	slash_removed_str = remove_slash_from_rule_list(rule_list);
	rule_str_anytype.list = slash_removed_str;
	filtered = void_list_filter2(curr_lst, func_wrap, rule_str_anytype);
	void_list_clear(&slash_removed_str, free_ex_token);
	return (filtered);
}
