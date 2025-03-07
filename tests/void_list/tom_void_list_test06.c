#include "list.h"
#include <stdlib.h>
#include <stdbool.h>

bool cmp(t_anytype a, t_anytype b)
{
	return (a.i32 < b.i32);
}

/// sortのテスト
/// ```bash
/// make vtest TEST_FILE=tests/void_list/tom_void_list_test06.c
/// ```
int main()
{
	t_void_list *a;

	a = NULL;
	int_list_push(&a, 0);
	int_list_push(&a, 1);
	int_list_push(&a, 4);
	int_list_push(&a, 5);
	int_list_push(&a, 6);
	int_list_push(&a, 0);
	int_list_push(&a, 3);
	int_list_push(&a, 8);
	int_list_push(&a, 7);
	int_list_push(&a, 2);
	int_list_push(&a, 9);

	merge_sort(&a, cmp);
	int_list_print(a);
	int_list_clear(&a);
	return (0);
}
