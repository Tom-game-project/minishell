#include <stdlib.h>
#include "list.h"


/**
 * private get_back
 * @brief free: not required
 */
t_char_list *get_back(t_char_list *node)
{
	if (node == NULL)
		return (node);
	while (node -> next != NULL)
		node = node->next;
	return (node);
}

