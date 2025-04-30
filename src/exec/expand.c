#include "dict.h"
#include "expand_string.h"
#include "list.h"
#include "libft.h"
#include "path.h"
#include "test_tools.h"
#include "tom_asterisk.h"
#include <stdlib.h>
#include <unistd.h>

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

/// 文字列の辞書順比較用の関数
static bool cmp_str(t_anytype a, t_anytype b)
{
	char *a_str;
	char *b_str;

	a_str = a.str;
	b_str = b.str;
	while (*a_str != '\0' && *b_str != '\0')
	{
		if (*a_str < *b_str)
		{
			return (true);
		}
		else if (*a_str > *b_str)
		{
			return (false);
		}
		a_str++;
		b_str++;
	}
	return (*a_str < *b_str);
}

// TODO あとで消す
//static int print_vec_vec_str(int d, t_anytype elem)
//{
//	return (debug_dprintf(STDERR_FILENO, "[%d] %s\n", d, elem.ex_token->str));
//	
//}

static bool endwith_slash(char *str)
{
	return (str[ft_strlen(str) - 1] == '/');
}

// 二次元リスト
static bool
rule_end_with_slash(
	t_void_list *lst // Vec<Vec<ex_token>>
)
{
	int len;
	int str_lst_len;
	t_str_list *str_lst;
	t_void_list *node;

	len = void_list_len(lst);
	if (len == 0)
		return (false);
	str_lst = void_list_get_elem(lst, len - 1)->ptr.list;
	str_lst_len = str_list_len(str_lst); 
	node = void_list_get_elem(str_lst, str_lst_len - 1);
	debug_dprintf(
		STDERR_FILENO, 
		"last element of token list \"%s\"\n", 
		node->ptr.ex_token->str);
	return (endwith_slash(node->ptr.ex_token->str));
}

static bool is_dir_wrap_for_anytype(t_anytype elem)
{
	return (is_dir(elem.str));
}

static char *append_slash(char *str)
{
	char *rstr;

	rstr = ft_strjoin(str, "/");
	free(str);
	return (rstr);
}

/// アスタリスク展開
t_str_list *expand_env_var(char *str, t_str_dict *env)
{
	t_void_list *token_list;
	t_void_list *splited_list;
	t_str_list *path;
	t_str_list *result_list;

	token_list = expand_string2list2(str, env);
	splited_list = // Vec<Vec<ex_token>>
	       	split_token_list_by_slash(token_list);

	path = NULL;
	result_list = dir_walker(&path, splited_list);
	// 以下でディレクトリだけを検索の対象としていた場合の処理をする
	if (rule_end_with_slash(splited_list))
	{
		t_str_list *result_tmp;

		// ディレクトリだけを抽出する
		// スラッシュを戻す
		result_tmp = void_list_filter(&result_list, is_dir_wrap_for_anytype);
		str_list_clear(&result_list, free);
		result_list = result_tmp;
		str_list_map(&result_list, append_slash);
	}
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
	merge_sort(&result_list, cmp_str);
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
