#include "dict.h"
#include <stdlib.h>

/// 初期値を設定アリのnode生成
t_str_dict *str_dict_set(char *key, char *value)
{
	t_str_dict *node; 

	node = init_str_dict();
	if (node == NULL)
		return (NULL);

	node->key = key;
	node->value = value;
	return (node);
}
