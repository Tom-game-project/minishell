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

static bool	endwith_slash(char *str)
{
	return (str[ft_strlen(str) - 1] == '/');
}

static char	*remove_slash(char *str)
{
	if (endwith_slash(str))
		return (ft_substr(str, 0, ft_strlen(str) - 1));
	else
		return (ft_strdup(str));
}

static void	free_ex_token(t_anytype elem)
{
	free(elem.ex_token->str);
	free(elem.ex_token);
	return ;
}

/// スラッシュを取り除いた新しいリストを返却する関数
static t_void_list	*remove_slash_from_rule_list(t_void_list *lst)
{
	t_void_list	*rlist;
	t_void_list	*last_elem;
	t_anytype	elem;

	rlist = token_list_clone(lst, copy_token_list_node);
	last_elem = void_list_get_elem(rlist, void_list_len(lst) - 1);
	if (endwith_slash(last_elem->ptr.ex_token->str))
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

/// 引数に与えられたリストから、ルールに従っているパターンのディレクトリ及びファイル名を取り出す関数
t_str_list	*filter_paths_by_rule(t_str_list **node, t_void_list *rule_list)
{
	t_anytype	rule_str_anytype;

	rule_str_anytype.list = rule_list;
	return (void_list_filter2(node, func_wrap, rule_str_anytype));
}

/// TODO 修正の必要あり
/// リムーブした場合、ディレクトリを探している場合はディレクトリかどうかをチェックする
t_str_list	*filter_paths_by_rule_wrap(t_str_list **curr_lst,
		t_void_list *rule_list)
{
	t_str_list	*filtered;
	t_void_list	*slash_removed_str;

	slash_removed_str = remove_slash_from_rule_list(rule_list); // TODO
	filtered = filter_paths_by_rule(curr_lst, slash_removed_str);
	void_list_clear(&slash_removed_str, free_ex_token);
	return (filtered);
}
