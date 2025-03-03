#include "built_in.h"
#include "list.h"

void nop(void *a)
{
	(void) a;
}

/// # 関数
/// ```bash
/// make vtest TEST_FILE=tests/tom_built_in_test00.c
/// ```
int main()
{
	int exit_status;
	t_str_list *a;

	a = NULL;
	str_list_push(&a, "echo");
	str_list_push(&a, "-n");
	str_list_push(&a, "-n");
	str_list_push(&a, "-n");
	str_list_push(&a, "-n");

	str_list_push(&a, "echo");
	//str_list_push(&a, "hello");
	//str_list_push(&a, "world");

	exit_status = built_in_echo(a);

	str_list_clear(&a , nop);
	return (exit_status);
}
