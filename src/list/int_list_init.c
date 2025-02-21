#include "list.h"
#include <stdlib.h>

///
t_int_list *init_int_list(int i)
{
	t_int_list *node;

	node = (t_int_list *)malloc(sizeof(t_int_list));
	if (node == NULL)
		return (NULL);
	node->next = NULL;
	node->i = i;
	return (node);
}
