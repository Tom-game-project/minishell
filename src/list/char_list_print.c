#include "list.h"
#include <stdio.h>

int char_list_print(t_char_list *node)
{
	int l;
	int i;

	l = char_list_len(node);
	i = 0;
	while (i < l)
	{
		printf("[%c]", char_list_get_elem(node, i));
		i += 1;
	}
	printf("\n");
	return (0);
}
