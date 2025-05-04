#include "list.h"
#include <stdio.h>

/// ```bash
/// make test TEST_FILE=tests/void_list/tom_void_list_test10.c
/// ```
int main()
{
	t_void_list *lst;

	t_void_list *lst1;
	lst = NULL;
	str_list_push(&lst, "hello world1");
	str_list_push(&lst, "hello world2");
	str_list_push(&lst, "hello world3");

	lst1 = str_list_cut(&lst, 3);
	printf("lst\n");
	str_list_print(lst);
	printf("lst1\n");
	str_list_print(lst1);
	return (0);
}
