#include "exec.h"
#include "list.h"
#include "test_tools.h"
#include <stdlib.h>
#include <unistd.h>


///
/// ```
/// make test TEST_FILE=tests/tom_asterisk_tests/test04.c
/// ```
int main()
{
	t_str_list *lst;
	//char *str;

	lst = split_path("src/*");
	get_all_path("", &lst);
	str_list_clear(&lst, free);
	return (0);
}
