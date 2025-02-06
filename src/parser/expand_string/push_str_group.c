#include "list.h"
#include <stdbool.h>
#include "expand_string.h"

/// str_groupをrlistに追加する
int push_str_group(t_list_args *group_args)
{
	if (!char_list_is_empty(*group_args->str_group))
	{
		str_list_push(group_args->rlist, char_list_to_str(*group_args->str_group));
		char_list_clear(group_args->str_group);
	}
	return (0);
}
