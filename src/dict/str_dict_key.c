#include "dict.h"
#include "strtools.h"
#include <stdlib.h>
#include <stdbool.h>
// for test
//
#include <stdio.h>
#include <unistd.h>

/// keyが見つからない場合はNULLを返却する
/// keyが見つかった場合は`t_str_dict *`を返す
t_str_dict *get_str_dict_by_key(\
		t_str_dict *node, char *key)
{
	while (node != NULL)
	{
		// dprintf(STDERR_FILENO, "hello world [%s]\n", node->key);
		if (ft_streq(node->key, key))
			return (node);
		node = node->next;
	}
	return (NULL);
}
