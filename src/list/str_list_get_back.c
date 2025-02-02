#include "list.h"
#include <stdlib.h>


t_str_list *str_list_get_back(t_str_list *node)
{
	if (node == NULL)
		return (node);
	while (node -> next != NULL)
		node = node->next;
	return (node);
}
