#include "dict.h"
#include "expand_string.h"
#include "list.h"
#include "tom_asterisk.h"
#include <stdlib.h>

static void free_ex_token(t_anytype elem)
{
	free(elem.ex_token->str);
	free(elem.ex_token);
	return ;
}

static void free_vec_vec_str(t_anytype elem)
{
	(void) elem;
}

/// アスタリスク展開
t_str_list *expand_env_var(char *str, t_str_dict *env)
{
	t_void_list *token_list;
	t_void_list *splited_list;
	t_str_list *path;
	t_str_list *result_list;

	token_list = expand_string2list2(str, env);
	splited_list = split_token_list_by_slash(token_list); // 二次元リスト
	path = NULL;
	result_list = dir_walker(&path, splited_list);
	if (str_list_len(result_list) == 0)
	{
		str_list_clear(&result_list, free);
		str_list_push(&result_list, token_list_join(token_list));
		/// 環境変数展開済みのtoken listが入ったものをくっつける
		/// stringにするそれを一つ要素に持つVec<string>を返す
	}
	str_list_clear(&path, free);
	void_list_clear(&token_list, free_ex_token);
	clear_split_token_list(&splited_list);
	return (result_list);
}

/// 未展開の引数リストを受け取って、展開済みの新しい引数を返却する
t_str_list *expand_env_vars(t_str_list *args, t_str_dict *env)
{
	t_void_list *vec_vec_str;// Vec<Vec<str>>
	t_str_list *rlist;

	vec_vec_str = NULL;
	while (args != NULL)
	{
		t_anytype elem;

		elem.list = expand_env_var(args->ptr.str, env);
		void_list_push(&vec_vec_str, elem);
		args = args->next;
	}
	rlist = list_list_all_concat(vec_vec_str);
	void_list_clear(&vec_vec_str, free_vec_vec_str);
	return (rlist);
}
