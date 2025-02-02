#include "list.h"
#include <stdlib.h>

int str_list_clear(t_str_list **node)
{
	while (str_list_pop(node, 0) != NULL)
	{}
	return (0);
}
