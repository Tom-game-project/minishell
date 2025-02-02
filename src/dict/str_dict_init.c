#include "dict.h"
#include <stdlib.h>

t_str_dict *init_str_dict()
{
	t_str_dict	*node;

	node = (t_str_dict *)malloc(sizeof(t_str_dict));
	if (node == NULL)
		return (NULL);
	node->next = NULL;
	node->key = NULL;
	node->value = NULL;
	return (node);
}
