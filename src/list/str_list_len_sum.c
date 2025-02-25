#include "list.h"
#include "libft.h"

#include <stdlib.h>

/// 格納している文字列の長さの合計
int str_list_len_sum(t_str_list *node)
{
	int i;

	i = 0;
	while (node != NULL)
	{
		i += ft_strlen(node->ptr.str);
		node = node->next;
	}
	return (i);
}
