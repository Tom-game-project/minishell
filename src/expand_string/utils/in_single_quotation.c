#include "list.h"
#include "expand_string.h"

/// シングルクォーテーション内の処理
t_anchor anchor_q_proc(char c, t_list_args *group_args)
{
	if (c == '\'') // quotation close
	{
		push_str_group(group_args);
		return (e_anchor_out);
	}
	else
		char_list_push(group_args->str_group, c);
	// `"`を普通の文字と同じように解釈する
	return (e_anchor_q);
}
