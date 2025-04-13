#include "exec.h"
#include "test_tools.h"
#include <unistd.h>
#include <stdlib.h>

/// ```
/// make test TEST_FILE=tests/tom_asterisk_tests/test03.c
/// ```
int main()
{
	char *str = "hello/";
	char *new_str;

	new_str = gen_formatted_asterisk_rule(str);
	debug_dprintf(STDERR_FILENO, "string : %s\n", new_str);
	free(new_str);
	return (0);
}
