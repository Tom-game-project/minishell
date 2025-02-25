#include "list.h"
#include "void_list.h"

static
t_anytype strip_str_list_func(t_anytype elem, void *(*f)(void *))
{
	t_anytype e;

	e.str = f(elem.str);
	return (e);
}

/// t_str_listの各要素に対して、関数fを適用する
int str_list_map(t_str_list **node, char *(*f)(char *))
{
	return (
		void_list_map(
			node,
		       	strip_str_list_func,
		       	(t_v2vfunc)f
		)
	);
}

static
t_anytype strip_str_list_func2(
	       	t_anytype elem, void *(*f)(void *, void *), void *str
)
{
	t_anytype e;

	e.str = f(elem.str, str);
	return (e);
}

/// t_str_listの各要素に対して、関数fを適用する
/// 適用する関数の第二引数に常に`str_list_map_arg1`が与えられる
int str_list_map_arg1(t_str_list **node, char *(*f)(char *,char *), char *str)
{
	return (
		void_list_map_arg1(
			node,
			strip_str_list_func2,
			(t_vv2vfunc) f,
			(void *) str
		)
	);
}
