#include "dict.h"
#include <stdlib.h>
#include "str_dict.h"

/// 与えられた`key`の要素を削除する
///
int str_dict_remove(t_str_dict **node, char *key, void (*key_free)(void *), void (*value_free)(void *))
{
	t_str_dict *pnode; // 一個前の要素
	t_str_dict *cur_node; // 今の要素

	pnode = NULL;
	cur_node = *node;
	while (cur_node != NULL)
	{
		if (ft_streq((cur_node)->key, key))
		{
			key_free(cur_node->key);
			value_free(cur_node->value);
			if (pnode == NULL)
			{
				free(cur_node);
				*node = NULL;
			}
			else
			{
				pnode->next = cur_node->next;
				free(cur_node);
			}
			return (0); // keyの重複は無いはずなので、ここで終了
		}
		pnode = cur_node; // 一個前の、要素を保持する
		cur_node = cur_node->next;
	}
	return (0);
}
 
