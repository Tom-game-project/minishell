#include "dict.h"
#include <stdlib.h>


/// str_dict_push関数が正しく追加できるかどうかを確かめる関数
int main()
{
	t_str_dict *a;

	a = NULL;
	str_dict_push(&a, "hello", "world");
	str_dict_push(&a, "world", "hello");
	str_dict_print(a);
	return (0);
}
