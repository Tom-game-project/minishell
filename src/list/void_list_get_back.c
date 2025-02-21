#include "list.h"
#include <stdlib.h>

t_void_list *void_list_get_back(t_void_list *node)
{
	if (node == NULL)
		return (NULL);
	while (node->next != NULL)
	{
		node = node->next;
	}
	return (node);
}
