#include "exec.h"
#include "list.h"
#include <stdlib.h>


/// ```
/// make test TEST_FILE=tests/tom_asterisk_tests/test05.c
/// ```
int main()
{
	t_str_list *lst;

	lst = rule_to_lst("hello*lll*world*");
	str_list_print(lst);
	str_list_clear(&lst, free);
	return (0);
}
