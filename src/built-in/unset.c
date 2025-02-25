#include "dict.h"
#include "list.h"
#include <stdlib.h>

/// 
/// unsetしようとしている環境変数が見つからなかったとしても
/// 問題ない
int built_in_unset(
	t_str_list *args,
	t_str_dict **envp_dict
)
{
	while (args != NULL)
	{
		str_dict_remove(envp_dict, args->ptr.str, free, free);
		args = args->next;
	}
	return (0);
}
