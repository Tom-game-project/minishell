#include "list.h"
#include <stdlib.h>


#include <stdio.h>

int void_list_push(t_void_list **node, t_anytype ptr)
{
	t_void_list *back_node;

	back_node = void_list_get_back(*node);
	if (back_node == NULL)
	{
		*node = void_list_init(ptr);
		return (0);
	}
	back_node->next = void_list_init(ptr);
	return (0);
}
