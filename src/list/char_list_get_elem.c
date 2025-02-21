#include "list.h"
#include <stdlib.h>

/// 存在しないindexを指定した場合はNULL文字を返却
char	char_list_get_elem(t_char_list *node, int index)
{
	t_void_list *a;

	a = void_list_get_elem(node, index);
	if (a == NULL)
		return ('\0');
	return (a->ptr.c);
}

