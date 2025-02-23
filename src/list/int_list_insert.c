#include "list.h"

/// 任意のindexにintを格納する
int int_list_insert(t_int_list **node, int index, int i)
{
	t_anytype elem;

	elem.i32 = i;
	return (void_list_insert(node, index, elem));
}
