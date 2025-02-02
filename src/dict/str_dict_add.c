#include "dict.h"
#include <stdlib.h>

// for test
#include <stdio.h>

/// もし、すでに同じkeyが存在するときは更新
/// ない場合は新規作成
int str_dict_add(t_str_dict **node, char *key, char *value)
{
	t_str_dict *sd;

	sd = get_str_dict_by_key(*node, key);
	if (sd == NULL)
		str_dict_push(node, key, value);
	else
		sd->value = value;
	return (0);
}

