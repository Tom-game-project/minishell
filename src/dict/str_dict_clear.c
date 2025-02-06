#include "dict.h"
#include <stdlib.h>

/// すべてをclearします
/// 第二第三引数に渡された関数によって、それぞれ、stringを解放しつつ
/// 自分自身を解放します
int str_dict_clear(t_str_dict **node, \
		void (*key_free)(void *),\
		void (*value_free)(void *)
		)
{
	t_str_dict *p;
	t_str_dict *pn;

	p = *node;
	while (p != NULL)
	{
		key_free(p->key);
		value_free(p->value);
		pn = p;
		p = p->next;
		free(pn);
	}
	*node = NULL;
	return (0);
}
