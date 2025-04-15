#include "exec.h"
#include "list.h"
#include "test_tools.h"
#include <unistd.h>
#include <stdlib.h>

/// ```
/// make test TEST_FILE=tests/tom_asterisk_tests/test09.c
/// ```
int test(char *str)
{
	t_str_list *path;
	t_str_list *splited_list;

	t_str_list *result_list;
	path = NULL;
	//splited_list = split_path("src/*.c");
	//splited_list = split_path("src/ex*/");
	//splited_list = split_path("./src/ex*/");
	//splited_list = split_path("./src/ex*/*.c");
	//splited_list = split_path("../minishell/src/list/*.c");
	//splited_list = split_path("../mini*/*.sh");
	//splited_list = split_path("/bin/x86*gcc*");
	//splited_list = split_path("/bin/*linux*gcc*");
	//splited_list = split_path("/bin/gcc*13");
	splited_list = split_path(str);


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

int main()
{
	char *test_case[9] = {
		"src/*.c",
		"src/ex*/",
		"./src/ex*/",
		"./src/ex*/*.c",
		"../minishell/src/list/*.c",
		"../mini*/*.sh",
		"/bin/x86*gcc*",
		"/bin/*linux*gcc*",
		"/bin/gcc*13"
	};

	int i;

	i = 0;
	while (i < 9)
	{
		test(test_case[i]);
		i += 1;
	}
	return (0);
}
