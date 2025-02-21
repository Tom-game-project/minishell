#include "list.h"
#include <stdlib.h>

int int_list_push(t_int_list **node, int i)
{
	t_int_list	*back_node_p;
	t_int_list	*new_node_p;

	new_node_p = init_int_list(i);
	if (new_node_p == NULL)
		return (1);
	back_node_p = char_list_get_back(*node);
	if (back_node_p == NULL)
	{
		*node = new_node_p;
		return (0);
	}
	back_node_p->next = new_node_p;
	return (0);

}
