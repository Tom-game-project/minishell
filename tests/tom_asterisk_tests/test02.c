#include "exec.h"

#include "list.h"
#include "test_tools.h"
#include "path.h"
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
/// make test TEST_FILE=tests/tom_asterisk_tests/test02.c
/// ```
/// 
int main()
{
	t_str_list *all_path;


	t_str_list *filtered;

	all_path = get_dir_list(".");
	//filtered = get_all_file_and_path(&all_path, "*.txt");
	//filtered = get_all_file_and_path(&all_path, "*tfi*");
	filtered = get_all_file_and_path(&all_path, "bash*.sh");
	//filtered = get_all_file_and_path(&all_path, "*.c");
	debug_dprintf(STDERR_FILENO, "--- A ---\n");
	merge_sort(&filtered, cmp_str);
	str_list_print(filtered);
	debug_dprintf(STDERR_FILENO, "--- B ---\n");
	str_list_print(all_path);
	str_list_clear(&all_path, free);
	str_list_clear(&filtered, free);
	return (0);
}
