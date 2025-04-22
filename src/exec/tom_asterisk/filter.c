#include "list.h"
#include <stdlib.h>
#include "exec.h"
#include "libft.h"

static bool endwith_srash(char *str)
{
	int len;

	len = ft_strlen(str);
	return (str[len - 1] == '/');
}

static char *
remove_slash(char *str)
{
	if (endwith_srash(str))
		return (ft_substr(str, 0, ft_strlen(str) - 1));
	else
		return (ft_strdup(str));
}

static bool func_wrap(t_anytype a, t_anytype b) 
{
	t_char_list *c_lst;
	t_str_list *rule_lst;
	bool r;

	c_lst = NULL;
	char_list_push_str(&c_lst, a.str);
	rule_lst = rule_to_lst(b.str);
	r = is_same_string(c_lst, rule_lst);
	char_list_clear(&c_lst);
	str_list_clear(&rule_lst, free);
	return (r);
}

/// 引数に与えられたリストから、ルールに従っているパターンのディレクトリ及びファイル名を取り出す関数
t_str_list *filter_paths_by_rule(t_str_list **node, char *rule_str)
{
	t_anytype rule_str_anytype;

	rule_str_anytype.str = rule_str;
	return (void_list_filter2(
		node,
	       	func_wrap,
	       	rule_str_anytype
	));
}

t_str_list *filter_paths_by_rule_wrap(
	t_str_list **curr_lst, 
	char *rule)
{
	t_str_list *filtered; 
	char *slash_removed_str;

	slash_removed_str = remove_slash(rule);
	filtered = filter_paths_by_rule(curr_lst, slash_removed_str);
	free(slash_removed_str);
	return (filtered);
}


// この階層まで、アスタリスクの情報が必要


