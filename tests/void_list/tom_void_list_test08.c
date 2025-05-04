#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_odd(t_anytype a)
{
	return (a.i32 % 2);
}



/// ```bash
/// make test TEST_FILE=tests/void_list/tom_void_list_test08.c
/// ```
int main()
{
	t_int_list *a;
	t_int_list *b;

	a = NULL;
	int_list_push(&a, 1);
	int_list_push(&a, 2);
	int_list_push(&a, 3);
	int_list_push(&a, 4);
	int_list_push(&a, 5);
	int_list_push(&a, 6);
	int_list_push(&a, 7);
	int_list_push(&a, 8);
	int_list_push(&a, 9);
	int_list_push(&a, 10);

	b = void_list_filter(&a, is_odd);
	printf("--- a ---\n");
	int_list_print(a);
	printf("--- b --- \n");
	int_list_print(b);
	int_list_clear(&a);
	int_list_clear(&b);
	return (0);
}
