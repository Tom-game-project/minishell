#include "list.h"
#include <stdlib.h>

/// # tom_str_list.c
/// 
/// ```bash
/// make test TEST_FILE=tests/tom_str_list_test05.c
/// ```
int main()
{
	t_str_list *a;
	char *str;

	str = "1aaaa1:2bbbb2:3cccccccc3:4eee4:5ffff5";
	//str = "1aaaa1:2bbbb2,3cccccccc3:4eee4,5ffff5";
	a = NULL;
	a = str_list_split(str , ':');
	str_list_print(a);
	str_list_clear(&a, free);
	return (0);
}
