#include "list.h"
#include <stdlib.h>

t_str_list *str_list_get_ptr(t_str_list *head, int index)
{
	t_str_list *tmp;
	int c;
	
	c= 0;
	tmp = head;
	while (tmp != NULL)
	{
		if (index == c)
			return (tmp);
		tmp = tmp->next;
		c += 1;
	}
	return (NULL);
}
