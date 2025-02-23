#include "list.h"
#include <stdlib.h>

int void_list_len(t_void_list *node)
{
	int i;

	i = 0;
	while (node != NULL)
	{
		i += 1;
		node = node->next;
	}
	return (i);
}
