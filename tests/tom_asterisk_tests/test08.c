#include "exec.h"
#include "list.h"
#include "test_tools.h"

#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>

bool tester(char *str, char *rule_str)
{
	t_char_list *target_lst;
	t_str_list *rule_lst;
	bool r;

	target_lst = NULL;
	char_list_push_str(&target_lst, str);
	rule_lst = rule_to_lst(rule_str);
	r = is_same_string(target_lst, rule_lst);
	char_list_clear(&target_lst);
	str_list_clear(&rule_lst, free);
	return (
		r
	);
}

/// ```
/// make test TEST_FILE=tests/tom_asterisk_tests/test08.c
/// ```
int main()
{
	//char *str = "hellohelloworld123.c.c";
	//char *rule = "*helloworld*.c";
	char *str = " hello     world";
	//char *str = "world hello";
	char *rule = "*hello*world*";

	debug_dprintf(
			STDERR_FILENO,
			"::: %b\n" , tester(str, rule)
	);

	return (0);
}
