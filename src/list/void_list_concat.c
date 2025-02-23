#include <stdlib.h>
#include "list.h"

int void_list_concat(t_void_list **a, t_void_list *b)
{
	t_void_list *node;

	if (*a == NULL)
		return (*a = b, 0);
	node = str_list_get_back(*a);
	node->next = b;
	return (0);
}
