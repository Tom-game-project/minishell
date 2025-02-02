#include "list.h"


int	char_list_get_elem(t_char_list *node, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		i += 1;
		node = node -> next;
	}
	return (node -> data);
}

