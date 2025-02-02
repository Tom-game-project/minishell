#include "dict.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
	t_str_dict *a;

	a = NULL;
	str_dict_add(&a, "hello", "world");
	str_dict_add(&a, "world", "hello");
	str_dict_add(&a, "tom", "0427");
	str_dict_add(&a, "ara", "0613");
	str_dict_add(&a, "tuna", "$$$$");

	str_dict_add(&a, "hello", "(^_^)");
	str_dict_print(a);
	return (0);

}
