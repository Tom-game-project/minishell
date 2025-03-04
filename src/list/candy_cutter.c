#include "list.h"
#include <stdlib.h>

/// 改行がある部分までで切り取る関数
char *candy_cutter(t_str_list **lst, int index)
{
	t_str_list *t;
	char *str;

	t = str_list_cut(lst, index);
	str = str_list_join(t, "");
	str_list_clear(&t, free);
	return (str);
}
