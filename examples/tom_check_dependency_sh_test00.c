#include <stdio.h>
#include <unistd.h>

/// 
/// ```bash
/// make test TEST_FILE=tests/tom_check_dependency_sh_test00.c
/// ```
int main()
{
	dprintf(STDERR_FILENO, "hello world");
	return (0);
}
