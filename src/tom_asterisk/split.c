/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:55:22 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/02 18:55:23 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "list.h"
#include <stdlib.h>

static bool	is_slash(char *c)
{
	return (*c == '/');
}

/// pathを分解する関数
t_str_list	*split_path_by_slash(char *path)
{
	t_char_list	*char_lst;
	t_str_list	*str_lst;
	int			index;
	t_char_list	*group_char_lst;

	char_lst = NULL;
	str_lst = NULL;
	char_list_push_str(&char_lst, path);
	index = char_list_search_index(char_lst, is_slash);
	while (index != -1)
	{
		group_char_lst = char_list_cut(&char_lst, index);
		str_list_push(&str_lst, char_list_to_str(group_char_lst));
		index = char_list_search_index(char_lst, is_slash);
		char_list_clear(&group_char_lst);
	}
	if (char_list_len(char_lst) != 0)
	{
		str_list_push(&str_lst, char_list_to_str(char_lst));
	}
	char_list_clear(&char_lst);
	return (str_lst);
}

static int	push_list_to_list(t_void_list **vec_vec_extoken,
		t_void_list *vec_extoken)
{
	t_anytype	elem;

	elem.list = vec_extoken;
	void_list_push(vec_vec_extoken, elem);
	return (0);
}

static void	split_token_list_by_slash_helper(t_void_list *lst,
		t_void_list **vec_vec_extoken, t_void_list **vec_extoken)
{
	t_char_list	*c_list;
	t_char_list	*group_char_lst;
	int			index;

	c_list = NULL;
	char_list_push_str(&c_list, lst->ptr.ex_token->str);
	index = char_list_search_index(c_list, is_slash);
	while (index != -1)
	{
		group_char_lst = char_list_cut(&c_list, index);
		void_list_push(vec_extoken, alloc_ex_token(e_word,
				char_list_to_str(group_char_lst)));
		push_list_to_list(vec_vec_extoken, *vec_extoken);
		*vec_extoken = NULL;
		char_list_clear(&group_char_lst);
		index = char_list_search_index(c_list, is_slash);
	}
	if (char_list_len(c_list) != 0)
	{
		void_list_push(vec_extoken, alloc_ex_token(e_word,
				char_list_to_str(c_list)));
		char_list_clear(&c_list);
	}
}

///
/// token_listを受け取って、スラッシュ区切りにする
///
/// 返り値は二次元リストList<List<ex_token>>
/// ```
///   [(aaaaaa/)]
/// - [(bbbb)-(*)-(bb/)]
/// - [(ccccc/)]
/// - [(fileA)]
/// ```
t_void_list	*split_token_list_by_slash(t_void_list *lst)
{
	t_void_list	*vec_vec_extoken;
	t_void_list	*vec_extoken;

	vec_vec_extoken = NULL;
	vec_extoken = NULL;
	while (lst != NULL)
	{
		if (lst->ptr.ex_token->token_type == e_word)
		{
			split_token_list_by_slash_helper(lst, &vec_vec_extoken,
				&vec_extoken);
		}
		else
		{
			void_list_push(&vec_extoken, alloc_ex_token(e_asterisk,
					ft_strdup("*")));
		}
		lst = lst->next;
	}
	if (void_list_len(vec_extoken) != 0)
	{
		push_list_to_list(&vec_vec_extoken, vec_extoken);
	}
	return (vec_vec_extoken);
}
