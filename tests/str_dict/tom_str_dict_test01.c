#include "dict.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
	t_str_dict *a;
	t_str_dict *sd;

	a = NULL;
	str_dict_push(&a, "hello", "world");
	str_dict_push(&a, "world", "hello");

	str_dict_print(a);
	sd = get_str_dict_by_key(a, "hello");
	if (sd == NULL)
	{
		printf("nothing\n");
	}
	else
	{
		printf("value %s \n", sd->value);
	}
	// 
	sd = get_str_dict_by_key(a, "n");
	if (sd == NULL)
	{
		printf("nothing\n");
	}
	else
	{
		printf("value %s \n", sd->value);
	}
	return (0);
}
