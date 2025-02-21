#include <stdlib.h>
#include "list.h"


/**
 * private get_back
 * @brief free: not required
 */
t_int_list *int_list_get_back(t_int_list *node)
{
	if (node == NULL)
		return (node);
	while (node -> next != NULL)
		node = node->next;
	return (node);
}

