#include "dict.h"
#include <stdlib.h>

t_str_dict *str_dict_get_back(t_str_dict *node)
{
	if (node == NULL)
		return (node);
	while (node->next != NULL)
		node = node->next;
	return (node);
}
