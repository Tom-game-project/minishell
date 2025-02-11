#include "list.h"
#include <stdlib.h>

/// リストのindex番目に格納された文字列を取得する
char *str_list_get_elem(t_str_list *node, int index)
{
	int i;

	i = 0;
	while (node != NULL)
	{
		if (i == index)
			return (node->str);
		i += 1;
		node = node->next;
	}
	return (NULL);
}
