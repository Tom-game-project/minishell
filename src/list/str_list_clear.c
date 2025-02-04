#include "list.h"
#include <stdlib.h>

int str_list_clear(t_str_list **node, void (*f)(void *))
{
	char *str;

	str = str_list_pop(node, 0);
	f(str);
	while (str != NULL)
	{
		str = str_list_pop(node, 0);
		f(str);
	}
	return (0);
}
