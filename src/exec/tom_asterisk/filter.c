#include "list.h"
#include <stdlib.h>
#include "exec.h"
#include "libft.h"
#include "strtools.h"

t_anytype
copy_token_list_node(t_anytype elem)
{
	return (alloc_ex_token(elem.ex_token->token_type, ft_strdup(elem.ex_token->str)));
}


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

/// スラッシュを取り除いた新しいリストを返却する関数
static t_void_list *remove_slash_from_rule_list(t_void_list *lst)
{
	t_void_list *rlist;
	t_void_list *last_elem;
	t_anytype elem;

	rlist = token_list_clone(lst, copy_token_list_node);
	last_elem = void_list_get_elem(rlist, void_list_len(lst) - 1);

	if (endwith_srash(last_elem->ptr.ex_token->str))
	{
		void_list_pop(
			&rlist,
			void_list_len(lst) - 1,
			&elem
		);
		void_list_push (
			&rlist,
			 alloc_ex_token(e_word, remove_slash(elem.ex_token->str)));
		free(elem.ex_token->str);
		free(elem.ex_token);
		return (rlist);
	}
	else
	{
		return (rlist);
	}
}


static void free_ex_token(t_anytype elem)
{
	free(elem.ex_token->str);
	free(elem.ex_token);
	return ;
}


static bool func_wrap(
	t_anytype a,
	t_anytype b
)	
{
	t_char_list *c_lst;
	t_str_list *rule_lst;
	bool r;

	c_lst = NULL;
	char_list_push_str(&c_lst, a.str);
	rule_lst = b.list;
	r = is_same_string(c_lst, rule_lst);
	char_list_clear(&c_lst);
	//void_list_clear(&rule_lst, free_ex_token);
	return (r);
}

/// 引数に与えられたリストから、ルールに従っているパターンのディレクトリ及びファイル名を取り出す関数
t_str_list *filter_paths_by_rule(t_str_list **node, t_void_list *rule_list)
{
	t_anytype rule_str_anytype;

	rule_str_anytype.list = rule_list;
	return (void_list_filter2(
		node,
	       	func_wrap,
	       	rule_str_anytype
	));
}

t_str_list *filter_paths_by_rule_wrap
(
	t_str_list **curr_lst, 
	t_void_list *rule_list // ルールを格納したリスト
)
{
	t_str_list *filtered; 
	t_void_list *slash_removed_str;

	slash_removed_str = remove_slash_from_rule_list(rule_list); // TODO
	filtered = filter_paths_by_rule(curr_lst, slash_removed_str);
	void_list_clear(&slash_removed_str, free_ex_token);
	return (filtered);
}

// この階層まで、アスタリスクの情報が必要


