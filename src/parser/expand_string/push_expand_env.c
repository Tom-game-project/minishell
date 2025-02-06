#include "list.h"
#include "dict.h"
#include "libft.h"
#include "expand_string.h"
#include <stdio.h>

/// path_groupを展開してrlistに追加する
///
/// 環境変数の展開はここで行われる
int push_expand_env(t_list_args *group_args, t_str_dict *dict)
{
	t_str_dict *r;

	if (!char_list_is_empty(*group_args->path_group)) // 空じゃないとき
	{
		char_list_pop(group_args->path_group, 0); // `$`を取り除く
		r = get_str_dict_by_key(dict, char_list_to_str(*group_args->path_group));
		if (r == NULL)
		{
		}
		else
		{
			str_list_push(group_args->rlist, ft_strdup(r->value));
		}
		char_list_clear(group_args->path_group);
	}
	return (0);
}

