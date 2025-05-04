#include "list.h"
#include "dict.h"
#include "private.h"
#include <unistd.h>

t_anchor	dollar_proc(char c, t_list_args *group_args, t_str_dict *env_dicts)
{
	if (char_list_len(*group_args->path_group) == 1)
	{
		char_list_push(group_args->path_group, c);
		push_expand_env(group_args, env_dicts);
		push_str_group2(group_args, e_word);
	}
	else
	{
		push_expand_env(group_args, env_dicts);
		push_str_group2(group_args, e_word);
		char_list_push(group_args->path_group, c);
	}
	return (e_anchor_out);
}
