#include "list.h"
#include <stdlib.h>

/// nodeの要素をprintするための関数
int void_list_print(t_void_list *node, int (*print)(int, t_anytype))
{
	int i;

	i = 0;
	while (node != NULL)
	{
		print(i, node->ptr);
		node = node->next;
		i += 1;
	}
	return (0);
}
