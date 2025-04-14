#include "list.h"
#include "test_tools.h"
#include <stdlib.h>
#include "unistd.h"

/// ```
/// make test TEST_FILE=tests/str_list/tom_str_list_test15.c
/// ```
int main()
{
	t_str_list *lst;

	int i = 0;
	int j = 3;

	t_str_list *head_tmp;
	t_str_list *tmp;
	lst = NULL;
	str_list_push(&lst, "A");
	str_list_push(&lst, "B");
	str_list_push(&lst, "C");
	str_list_push(&lst, "D");
	str_list_push(&lst, "E");

	head_tmp = str_list_cut(&lst, i - 1);
	tmp =  str_list_cut(&lst, j - 1);

	debug_dprintf(STDERR_FILENO, "tmp\n");
	str_list_print(tmp);
	debug_dprintf(STDERR_FILENO, "(%d, %d)\n", i, j);
	str_list_concat(&head_tmp, tmp);
	str_list_concat(&head_tmp, lst);
	lst = head_tmp;
	str_list_print(lst);
	return (0);
}
