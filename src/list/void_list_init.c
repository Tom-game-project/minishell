#include "list.h"
#include <stdlib.h>

/// t_void_list 関数の初期化
t_void_list *void_list_init(t_anytype ptr)
{
	t_void_list *node;

	node = (t_void_list *) malloc(sizeof(t_void_list));
	if (node == NULL)
		return (NULL);
	node->ptr = ptr;
	node->next = NULL; 
	return (node);
}
