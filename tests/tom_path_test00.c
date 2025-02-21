#include "path.h"
#include <stdio.h>

/// ```bash
/// make test TEST_FILE=tests/tom_path_test00.c
/// ```
int main()
{
	char a[8];
	
	u32tostr(a, 1234);
	printf("hex %s\n", a);
	return (0);
}
