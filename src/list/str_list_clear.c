#include "list.h"
#include <stdlib.h>

int str_list_clear(t_str_list **node, void (*f)(void *))
{
	t_str_list *p;
	t_str_list *tmp;

	p = *node;
	while (p != NULL)
	{
		tmp = p;
		p = p->next;
		f(tmp->str);
		free(tmp);
	}
	return (0);
}

