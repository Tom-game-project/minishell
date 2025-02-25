#include "dict.h"
#include <stdlib.h>

// for test
#include <stdio.h>

/// もし、すでに同じkeyが存在するときは更新
/// ない場合は新規作成
///
/// 文字列を入れ替えるときにvalueのfreeが必要な場合は
/// 第4引数に`free`を入れる
int str_dict_add(t_str_dict **node, char *key, char *value, void (*f)(void *))
{
	t_str_dict *sd;

	sd = get_str_dict_by_key(*node, key);
	if (sd == NULL)
		str_dict_push(node, key, value);
	else
	{
		f(sd->value);
		sd->value = value;
	}
	return (0);
}

