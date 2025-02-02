#include "dict.h"
#include <stdlib.h>
#include <stdbool.h>

// for test
//
#include <stdio.h>


// TODO 後でlibft使用したものに置き換える
static int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i += 1;
	}
	return (i);
}

static bool ft_streq(char *a, char *b)
{
	if (ft_strlen(a) == ft_strlen(b))
	{
		while (*a != '\0')
		{
			if (*a != *b)
				return (false);
			a++;
			b++;
		}
		return (true);
	}
	else
		return (false);
}

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
