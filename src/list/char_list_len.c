#include "list.h"
#include <stdlib.h>

int	char_list_len(t_char_list *node)
{
	int	i;

	i = 0;
	while (node != NULL)
	{
		i += 1;
		node = node->next;
	}
	return (i);
}

