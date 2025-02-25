
#include "list.h"
#include "dict.h"
#include "envtools.h"
#include "private.h"


t_anchor anchor_dq_proc(char c, t_list_args *group_args, t_str_dict *env_dicts)
{
	if (c == '"')// double quotation open
	{
		push_expand_env(group_args, env_dicts);
		push_str_group(group_args);
		return (e_anchor_out);
	}
	else if (c == '$')
	{
		push_expand_env(group_args, env_dicts);
		push_str_group(group_args);
		char_list_push(group_args->path_group, c);
	}
	else
		if (!char_list_is_empty(*group_args->path_group))
			if (is_valid_env_char(c))
				char_list_push(group_args->path_group, c);
			else
			{
				push_expand_env(group_args, env_dicts);
				push_str_group(group_args);
				char_list_push(group_args->str_group, c);
			}
		else
			char_list_push(group_args->str_group, c);
	return (e_anchor_dq);
}



