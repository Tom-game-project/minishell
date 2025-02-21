#include "list.h"
#include <stdlib.h>

int *void_list_clear(t_void_list **node, void (*f)(t_anytype))
{
	t_void_list *tmp;

	while (*node != NULL)
	{
		tmp = (*node)->next;
		f((*node)->ptr);
		free(*node);
		*node = tmp;
	}
	return (0);
}
