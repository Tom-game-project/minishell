#include "list.h"
#include <stdio.h>

#include <stdlib.h>

/// 出力先を指定できる
int str_list_dprint(int fd, t_str_list *node)
{
	int i;

	i = 0;
	while (node != NULL)
	{
		dprintf(fd, "[%d] \"%s\"\n", i, node->ptr.str);
		node = node->next;
		i += 1;
	}
	return (0);
}
