#include "list.h"
#include <stdlib.h>
#include <stdio.h>


void nop(void *a)
{
	(void) a;
}

/// str_list_to_arrayのテスト
///
/// ```bash
/// make test TEST_FILE=tests/tom_str_list_test02.c
/// ```
int main()
{
	t_str_list *a;
	char **str_array;
	char **str_array_tmp;

	a = NULL;
	str_list_push(&a, "hello1");
	str_list_push(&a, "world");
	str_list_push(&a, "apple");
	str_list_push(&a, "orange");
	str_list_print(a);
	printf("len %d\n", str_list_len(a));
	printf("poped %s\n",str_list_pop(&a, 0));
	printf("poped %s\n",str_list_pop(&a, 1));
	printf("hello world\n");
	str_list_print(a);
	printf("len %d\n", str_list_len(a));

	//while ((s = str_list_pop(&a, 0)) != NULL)
	//{
	//	printf("rrr %s\n", s);
	//}

	str_array = str_list_to_array(a);
	str_array_tmp = str_array;
	while (*str_array != NULL)
	{
		printf(">>> %s\n", *str_array);
		free(*str_array);
		str_array++;
	}
	str_list_clear(&a, nop);
	free(str_array_tmp);
	return (0);
}


