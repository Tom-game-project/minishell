#include "dict.h"
#include <stdlib.h>
#include <stdio.h>

void nop(void *p)
{
	(void) p;
}

int main()
{
	t_str_dict *a;

	a = NULL;
	str_dict_add(&a, "hello", "world", nop);
	str_dict_add(&a, "world", "hello", nop);
	str_dict_add(&a, "tom", "0427", nop);
	str_dict_add(&a, "ara", "0613", nop);
	str_dict_add(&a, "tuna", "$$$$", nop);

	str_dict_add(&a, "hello", "(^_^)", nop);
	str_dict_print(a);
	return (0);

}
