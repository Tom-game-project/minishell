#include "exec.h"
#include "list.h"
#include "test_tools.h"
#include <unistd.h>
#include <stdlib.h>

/// 文字列の辞書順比較用の関数
static bool cmp_str(t_anytype a, t_anytype b)
{
	char *a_str;
	char *b_str;

	a_str = a.str;
	b_str = b.str;
	while (*a_str != '\0' && *b_str != '\0')
	{
		if (*a_str != *b_str)
			return (*a_str < *b_str);
		a_str++;
		b_str++;
	}
	return (*a_str < *b_str);
}

/// ```
/// make test TEST_FILE=tests/tom_asterisk_tests/test09.c
/// ```
int test(char *str)
{
	t_str_list *path;
	t_str_list *splited_list;

	t_str_list *result_list;
	path = NULL;
	splited_list = split_path(str);

	debug_dprintf(STDERR_FILENO, "--- splited_list ---\n");
	str_list_print(splited_list);
	result_list = get_all_path(&path, splited_list);
	debug_dprintf(STDERR_FILENO, "--- result_list ---\n");
	merge_sort(&result_list, cmp_str);

	str_list_print(result_list);
	str_list_clear(&path, free);
	str_list_clear(&splited_list, free);
	str_list_clear(&result_list, free);
	return (0);
}

int main()
{
	char *test_case[10] = {
		"src/*.c",
		"src/ex*/",
		"./src/ex*/",
		"./src/ex*/*.c",
		"./src/ex*/ex*.c",
		"../minishell/src/list/*.c",
		"../mini*/*.sh",
		"/bin/x86*gcc*",
		"/bin/*linux*gcc*",
		"/bin/gcc*13"
	};

	int i;

	i = 0;
	while (i < 10)
	{
		test(test_case[i]);
		i += 1;
	}
	return (0);
}
