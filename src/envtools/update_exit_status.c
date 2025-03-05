#include "dict.h"
#include "libft.h"
#include <stdlib.h>

/// `$?` exit status を更新する
///
///
/// TODO 急いで修正が必要
///
///
int update_exit_status(int exit_status, t_str_dict **env_dict)
{
	char *str_tmp;

	str_tmp = ft_strdup("?");
	if (str_dict_add(env_dict, str_tmp, ft_itoa(exit_status), free))
		// 更新されただけなのでstr_tmpはfreeして良い
	{
	}
	else
	{
		// 追加しているのでfreeしてはいけない
		free(str_tmp);
	}
	return (0);
}
