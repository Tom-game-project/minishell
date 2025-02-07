#include "list.h"
#include <stdlib.h>


/// ```bash
/// make test TEST_FILE=tests/tom_str_list_test04.c
/// ```
int main()
{
	t_str_list *a;
	t_str_list *node;

	a = NULL;
	str_list_push(&a, "cmd");
	str_list_push(&a, "arg1");
	str_list_push(&a, "arg2");
	node = str_list_get_ptr(a, 0);
	if (node != NULL)
		node->str = "hello";

	str_list_print(a);
	return (0);
}
