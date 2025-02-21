#include "list.h"
#include <stdlib.h>

/// clear
///
int int_list_clear(t_int_list **node)
{
	t_int_list *p;

	p = *node;
	while (p != NULL)
	{
		free(p);
		p = p->next;
	}
	return (0);
}
