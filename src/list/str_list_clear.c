#include "list.h"

/// 型を脱がす関数
static void strip_anytype(t_anytype elem, void (*f)(void *))
{
	f(elem.str);
}

/// str_listをclearする関数
int str_list_clear(t_str_list **node, void (*f)(void *))
{
	return (void_list_clear_func(node, strip_anytype, f));
}

