#include "list.h"
#include <stdlib.h>
#include <stdio.h>

static
void nop (void *a)
{
	(void) a;
}

/// トリミング用の関数のテスト
/// ```bash
/// make test TEST_FILE=tests/str_list/tom_str_list_test14.c
/// ```
int main()
{
	t_str_list *lst;

	lst = NULL;
	//str_list_push(&lst, " ");
	//str_list_push(&lst, " ");
	str_list_push(&lst, "hello world");
	str_list_push(&lst, " ");
	str_list_push(&lst, "this is TOm");
	//str_list_push(&lst, " ");
	//str_list_push(&lst, " ");

	t_str_list *set;

	int d;
	set = NULL;
	str_list_push(&set, " ");
	d = str_list_trim(&lst, set, nop);
	str_list_print(lst);
	printf("dd %d\n", d);
	str_list_clear(&lst, nop);
	str_list_clear(&set, nop);
	return (0);
}
