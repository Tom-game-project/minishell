#include "dict.h"
#include <stdlib.h>
#include <stdio.h>

/// key valueと一体になったデータを表示します
int str_dict_print(t_str_dict *node)
{
	while (node != NULL)
	{
		printf("%s=%s\n", node->key, node->value);
		node = node->next;
	}
	return (0);
}
