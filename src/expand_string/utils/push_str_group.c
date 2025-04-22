#include "list.h"
#include <stdbool.h>
#include "private.h"

/// str_groupをrlistに追加する
/// TODO: いずれ消す
int push_str_group(t_list_args *group_args)
{
	if (!char_list_is_empty(*group_args->str_group))
	{
		str_list_push(group_args->rlist, char_list_to_str(*group_args->str_group));
		char_list_clear(group_args->str_group);
	}
	return (0);
}


/// トークンリストに格納する
int push_str_group2(t_list_args *group_args, t_expand_token_type token_type)
{


	if (!char_list_is_empty(*group_args->str_group))
	{
		
		void_list_push(group_args->rlist, alloc_ex_token(token_type, char_list_to_str(*group_args->str_group)));
		char_list_clear(group_args->str_group);
	}
	return (0);
}
