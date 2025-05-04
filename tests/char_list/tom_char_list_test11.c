#include "list.h"
#include "test_tools.h"
#include <unistd.h>

/// ```
/// make test TEST_FILE=tests/char_list/tom_char_list_test11.c
/// ```
int main()
{
	t_char_list *lst;

	lst = NULL;
	char_list_push_str(&lst, "hello_world.c");
	if (char_list_endswith(lst, ".c"))
	{
		debug_dprintf(STDERR_FILENO, "True\n");
	}
	else
	{
		debug_dprintf(STDERR_FILENO, "False\n");
	}
	return (0);
}
