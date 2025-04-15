#include "exec.h"
#include "list.h"
#include "test_tools.h"
#include <unistd.h>
#include <stdlib.h>

/// ```
/// make test TEST_FILE=tests/tom_asterisk_tests/test09.c
/// ```
int main()
{
	t_str_list *path;
	t_str_list *splited_list;

	t_str_list *result_list;
	path = NULL;
	//splited_list = split_path("src/*.c");
	splited_list = split_path("src/ex*/");
	//splited_list = split_path("../minishell/src/list/*.c");
	//splited_list = split_path("../mini*/*.sh");
	//splited_list = split_path("/bin/x86*");

	debug_dprintf(STDERR_FILENO, "--- splited_list ---\n");
	str_list_print(splited_list);
	result_list = get_all_path(&path, splited_list);
	debug_dprintf(STDERR_FILENO, "--- result_list ---\n");

	str_list_print(result_list);
	str_list_clear(&path, free);
	str_list_clear(&splited_list, free);
	str_list_clear(&result_list, free);
	return (0);
}
