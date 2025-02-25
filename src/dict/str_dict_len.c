#include "dict.h"
#include <stdlib.h>

int str_dict_len(t_str_dict *node)
{
	int i;

	i = 0;
	while (node != NULL) {
		node = node->next;
		i+=1;
	}
	return (i);
}
