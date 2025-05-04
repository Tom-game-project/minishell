#include "exec.h"
#include "list.h"
#include "test_tools.h"
#include <stdlib.h>
#include <unistd.h>


int test_case00(char *str)
{
	t_str_list *lst;

	debug_dprintf(STDERR_FILENO,"--- test ---\n");
	lst = split_path(str);
	str_list_print(lst);
	str_list_clear(&lst, free);
	return (0);
}


/// ```
/// make test TEST_FILE=tests/tom_asterisk_tests/test00.c
/// ```
int main()
{
	//lst = split_path("/hello/world/this/is/tom");
	test_case00("hello/world/this/is/tom");
	test_case00("/hello/world/this/is/tom");
	test_case00("hello/world/this/is/tom/");
	test_case00("/hello/world/this/is/tom/");

	return (0);
}
