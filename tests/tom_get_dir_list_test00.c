#include "list.h"
#include "path.h"
#include <stdlib.h>

/// ```bash
/// make vtest TEST_FILE=tests/tom_get_dir_list_test00.c
/// ```
int main()
{
	t_str_list *a;

	a = get_dir_list("./");
	str_list_print(a);
	str_list_clear(&a, free);
	return (0);
}
