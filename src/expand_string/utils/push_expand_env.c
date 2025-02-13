#include "list.h"
#include "dict.h"
#include "libft.h"
#include "private.h"
#include <stdio.h>
#include <stdbool.h>

/// minishellは、bashの部分的なsubsetであり
/// minishell bonus,mandatory partのsupersetである
///
/// よって、bashの変数展開時の挙動は、完全にbashと一致することはない
///
/// 特に、bashで　`Built-in shell variables.`を`$?`にしか対応させないため、
/// それ以外の組み込み変数はを書いても正しく判定はしない
///


/// path_groupを展開してrlistに追加する
///
/// 環境変数の展開はここで行われる
/// 展開後にドル文字を含まないように消す処理がある。
/// この関数を使うユーザは、そのプログラムが本当に展開を必要とするかどうか
/// を未然にチェックする必要がある
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

