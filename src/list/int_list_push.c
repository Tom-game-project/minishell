#include "list.h"

int int_list_push(t_int_list **node, int i)
{
	t_anytype elem;

	elem.i32 = i;
	void_list_push(node, elem);
	return (0);
}
