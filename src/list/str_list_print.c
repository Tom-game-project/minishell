#include "list.h"
#include <stdlib.h>

#include <stdio.h>

int str_list_print(t_str_list *node)
{
	int i;

	i = 0;
	while (node != NULL)
	{
		printf("[%d] %s\n", i, node->str);
		node = node->next;
		i += 1;
	}
	return (0);
}
