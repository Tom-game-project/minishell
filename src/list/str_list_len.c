#include "list.h"
#include <stdlib.h>

int str_list_len(t_str_list *node)
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
