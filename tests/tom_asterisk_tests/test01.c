#include "exec.h"
#include "list.h"
#include "test_tools.h"
#include <stdlib.h>
#include <unistd.h>


bool func_wrap(char *str, char *rule_str) 
{
	t_char_list *c_lst;
	t_str_list *rule_lst;
	bool r;

	c_lst = NULL;
	char_list_push_str(&c_lst, str);
	rule_lst = rule_to_lst(rule_str);
	r = is_same_string(c_lst, rule_lst);
	char_list_clear(&c_lst);
	str_list_clear(&rule_lst, free);
	return (r);
}

/// ```
/// make test TEST_FILE=tests/tom_asterisk_tests/test01.c
/// ```
int main()
{
	//lst = split_path("/hello/world/this/is/tom");
	debug_dprintf(
		STDERR_FILENO,
		"bool %b\n", 
		func_wrap("aacgggfabfdddddc", "a*b*c")
	);
	debug_dprintf(
		STDERR_FILENO,
		"bool %b\n", 
		func_wrap("aacgggfabfdddddc", "*a*b*c*")
	);
	debug_dprintf(
		STDERR_FILENO,
		"bool %b\n", 
		func_wrap("hello.c", "*.c")
	);
	debug_dprintf(
		STDERR_FILENO,
		"bool %b\n", 
		func_wrap("hello.rs", "*.c")
	);
	debug_dprintf(// これは正しい
		STDERR_FILENO,
		"bool %b\n", 
		func_wrap("lslslslsls.hello.slslslslslslsls", "*.hello.*")
	);
	debug_dprintf(// これは正しい
		STDERR_FILENO,
		"bool %b\n", 
		func_wrap("infile000", "infile*")
	);
	return (0);
}
