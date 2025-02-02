#include "list.h"
#include <stdlib.h>

int str_list_len(t_str_list *node)
{
	int i;

	i = 0;
	while (node != NULL)
	{
		node = node->next;
		i += 1;
	}
	return (i);
}
