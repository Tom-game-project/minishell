#include "dict.h"
#include <stdlib.h>
#include <stdbool.h>
#include "str_dict.h"

// for test
//
#include <stdio.h>

/// keyが見つからない場合はNULLを返却する
/// keyが見つかった場合は`t_str_dict *`を返す
t_str_dict *get_str_dict_by_key(\
		t_str_dict *node, char *key)
{
	while (node != NULL)
	{
		if (ft_streq(node->key, key))
			return (node);
		node = node->next;
	}
	return (NULL);
}
