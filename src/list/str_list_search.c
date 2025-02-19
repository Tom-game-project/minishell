#include "list.h"
#include <stdlib.h>
#include <stdbool.h>



/// 条件に当てはまった、リストの中の文字列、を探し返す。条件に当てはまる.
///
char *str_list_search(t_str_list *node, bool (*f)(char *))
{
	while (node != NULL)
	{
		if (f(node->str))
			return (node->str);
		node = node->next;
	}
	return (NULL);
}


int str_list_search_index(t_str_list *node, bool (*f)(char *))
{
	int i;

	i = 0;
	while (node != NULL)
	{
		if (f(node->str))
			return (i);
		node = node->next;
		i += 1;
	}
	return (-1);
}
