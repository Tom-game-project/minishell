#include "dict.h"
#include "str_dict.h"
#include <stdlib.h>
//
#include <stdio.h>


/// すでにkeyがあるかどうかを確認せずに追加する
int str_dict_push(t_str_dict **node, char *key, char *value)
{
	t_str_dict	*back_node_p;
	t_str_dict	*new_node_p;

	new_node_p = str_dict_set(key, value);
	if (new_node_p == NULL)
		return (1);
	back_node_p = str_dict_get_back(*node);
	if (back_node_p == NULL)
	{
	//	printf("%p %p\n", *node, new_node_p);
		*node = new_node_p;
		//exit(0);
		return (0);
	}
	back_node_p->next = new_node_p;
	return (0);
}

