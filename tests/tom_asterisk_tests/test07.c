#include "exec.h"
#include "list.h"
#include "test_tools.h"
#include <unistd.h>

bool func(t_char_list *str_lst, t_str_list *rule_lst)
{
	(void) rule_lst;

	debug_dprintf(STDERR_FILENO, "----\n");
	char_list_print(str_lst);
	return (false);
}

/// ```
/// make test TEST_FILE=tests/tom_asterisk_tests/test07.c
int main()
{
	t_str_list *a;
	t_str_list *rule;

	rule = NULL;
	a = NULL;
	char_list_push(&a, 'a');
	char_list_push(&a, 'b');
	char_list_push(&a, 'c');
	char_list_push(&a, 'd');

	comb2_any(a, rule, func);
	char_list_clear(&a);
	return (0);
}
