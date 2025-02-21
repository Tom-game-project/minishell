#include "list.h"
#include <stdlib.h>

/// 指定されたindexのnodeを返却する
t_void_list *void_list_get_elem(t_void_list *node, int index)
{
	int i;

	i = 0;
	while (node != NULL)
	{
		if (i == index)
			return (node);
		node = node->next;
		i += 1;
	}
	return (NULL);
}
