// out of quotation
#include "list.h"
#include "dict.h"
#include "expand_string.h"

static t_anchor single_quotation_proc(char c, t_list_args *group_args, t_str_dict *env_dicts)
{
	(void) c;
	push_expand_env(group_args, env_dicts);
	push_str_group(group_args);
	return (e_anchor_q);
}

static t_anchor double_quotation_proc(char c, t_list_args *group_args, t_str_dict *env_dicts)
{
	(void) c;
	push_expand_env(group_args, env_dicts);
	push_str_group(group_args);
	return (e_anchor_dq);
}

static t_anchor dollar_proc(char c, t_list_args *group_args, t_str_dict *env_dicts)
{	
	if (char_list_len(*group_args->path_group) == 1)
	{
		char_list_push(group_args->path_group, c);
		push_expand_env(group_args, env_dicts);
		push_str_group(group_args);
	}
	else
	{
		push_expand_env(group_args, env_dicts);
		push_str_group(group_args);
		char_list_push(group_args->path_group, c);
	}
	return (e_anchor_out);
}

static t_anchor question_proc(char c, t_list_args *group_args, t_str_dict *env_dicts)
{
		if (char_list_len(*group_args->path_group) == 1)
		{
			char_list_push(group_args->path_group, c);
			push_expand_env(group_args, env_dicts);
			push_str_group(group_args);
		}
		else if (char_list_len(*group_args->path_group) == 0)
		{
			char_list_push(group_args->str_group, c);
		}
		else
		{
			push_expand_env(group_args, env_dicts);
			char_list_push(group_args->str_group, c);
		}
	return (e_anchor_out);
}

/// クォーテーション外の処理
t_anchor anchor_out_proc(char c, t_list_args *group_args, t_str_dict *env_dicts)
{
	if (c == '\'') // quotation open
		return (single_quotation_proc(c, group_args, env_dicts));
	else if (c == '"')// double quotation open
		return (double_quotation_proc(c, group_args, env_dicts));
	else if (c == '$')
		return (dollar_proc(c, group_args, env_dicts));
	else if (c == '?')
		return (question_proc(c, group_args, env_dicts));
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
	return (e_anchor_out);
}

