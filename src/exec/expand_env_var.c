/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:38:16 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/04 15:38:18 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "expand_string.h"
#include "tom_asterisk.h"
#include "libft.h"
#include "path.h"
#include "strtools.h"

static bool	rule_end_with_slash(t_void_list *lst)
{
	int			len;
	int			str_lst_len;
	t_str_list	*str_lst;
	t_void_list	*node;
	char *str;

	len = void_list_len(lst);
	if (len == 0)
		return (false);
	str_lst = void_list_get_elem(lst, len - 1)->ptr.list;
	str_lst_len = str_list_len(str_lst);
	node = void_list_get_elem(str_lst, str_lst_len - 1);
	str = node->ptr.ex_token->str;
	return (str[ft_strlen(str) - 1] == '/');
}

static bool	is_dir_wrap_for_anytype(t_anytype elem)
{
	return (is_dir(elem.str));
}

static char	*append_slash(char *str)
{
	char	*rstr;

	rstr = ft_strjoin(str, "/");
	free(str);
	return (rstr);
}

static void	filter_normal_file_and_set(t_str_list **result_list)
{
	t_str_list	*result_tmp;

	result_tmp = void_list_filter(result_list, is_dir_wrap_for_anytype);
	str_list_clear(result_list, free);
	*result_list = result_tmp;
	str_list_map(result_list, append_slash);
}

/// アスタリスク展開
/// split_listはVec<Vec<ex_token>>
t_str_list	*expand_env_var(char *str, t_str_dict *env)
{
	t_void_list	*token_list;
	t_void_list	*splited_list;
	t_str_list	*path;
	t_str_list	*result_list;

	token_list = expand_string2list2(str, env);
	splited_list = split_token_list_by_slash(token_list);
	path = NULL;
	result_list = dir_walker(&path, splited_list);
	if (rule_end_with_slash(splited_list))
	{
		filter_normal_file_and_set(&result_list);
	}
	if (str_list_len(result_list) == 0)
	{
		str_list_clear(&result_list, free);
		str_list_push(&result_list, token_list_join(token_list));
	}
	str_list_clear(&path, free);
	void_list_clear(&token_list, free_ex_token);
	clear_split_token_list(&splited_list);
	merge_sort(&result_list, cmp_str);
	return (result_list);
}
