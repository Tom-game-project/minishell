#include "list.h"
#include <stdlib.h>

/// リストのindex番目に格納された文字列を取得する
char *str_list_get_elem(t_str_list *node, int index)
{
	t_void_list *p;

	p = void_list_get_elem(node, index);
	if (p == NULL)
		return (NULL);
	return (p->ptr.str);
}
