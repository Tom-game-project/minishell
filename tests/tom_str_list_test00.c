#include "list.h"
#include <stdio.h>
#include <stdlib.h>

/// # str_list_push関数のテスト
/// ```bash
/// make test TEST_FILE=tests/tom_str_list_test00.c
/// ```
int main()
{
	t_str_list *a;

	a = NULL;
	str_list_push(&a, "hello");
	str_list_push(&a, "world");
	str_list_push(&a, "world!");
	str_list_push(&a, "world");
	str_list_print(a);
	printf("len %d\n", str_list_len(a));
	printf("poped %s\n",str_list_pop(&a, 0));
	printf("poped %s\n",str_list_pop(&a, 1));
	return (0);
}
