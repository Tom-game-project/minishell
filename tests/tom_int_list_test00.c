#include "list.h"
#include <stdlib.h>
#include <stdio.h>


/// `int_list_push`関数のテスト
/// ```bash
/// make vtest TEST_FILE=tests/tom_int_list_test00.c
/// ```
int main()
{
	t_int_list *a;

	a = NULL;
	int_list_push(&a, 1);
	int_list_push(&a, 2);
	int_list_push(&a, 3);
	int_list_push(&a, 4);
	printf("length of list %d\n", int_list_len(a));
	int_list_print(a);
	int_list_clear(&a);
	return (0);
}
