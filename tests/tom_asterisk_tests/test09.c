#include "list.h"
#include "tom_asterisk.h"
#include "expand_string.h"
#include "dict.h"
#include "libft.h"
#include "test_tools.h"
#include <unistd.h>
#include <stdlib.h>


static void free_ex_token(t_anytype elem)
{
	free(elem.ex_token->str);
	free(elem.ex_token);
	return ;
}

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

int test(char *str)
{
	t_str_list *path;
	t_void_list *splited_list;
	t_str_dict *d;

	t_str_list *result_list;
	path = NULL;

	d = NULL;
	// 環境変数を模したもの
	str_dict_add(
		&d,
		ft_strdup("HELLO"),
		ft_strdup("HELLO_VALUE"), 
		free
	);
	str_dict_add(
		&d,
		ft_strdup("$"),
		ft_strdup("PID"), 
		free
	);
	str_dict_add(
		&d,
		ft_strdup("?"),
		ft_strdup("EXIT STATUS"), 
		free
	);

	t_void_list *token_list;
	token_list = expand_string2list2(str, d);
	splited_list = split_token_list_by_slash(token_list); // 二次元リスト

	result_list = dir_walker(&path, splited_list);
	debug_dprintf(STDERR_FILENO, "--- result_list ---\n");
	merge_sort(&result_list, cmp_str);

	str_list_print(result_list);
	str_list_clear(&path, free);
	clear_split_token_list(&splited_list);
	void_list_clear(&token_list, free_ex_token);
	str_list_clear(&result_list, free);
	str_dict_clear(&d, free, free);
	return (0);
}

/// ```
/// make vtest TEST_FILE=tests/tom_asterisk_tests/test09.c
/// ```
int main()
{
	char *test_case[14] = {
		"*",
		"*.c",
		"src/*.c",
		"src/ex*/",
		"./src/ex*/",
		"./src/ex*/*.c",
		"./src/ex*/ex*.c",
		"../minishell/src/list/*.c",
		"../mini*/*.sh",
		"/bin/x86*gcc*",
		"/bin/*linux*gcc*",
		"/bin/gcc*13",
		"/home/tom/*'*'*",
		"aaaaaaaaaaddddddd*"
	};

	int i;

	i = 0;
	while (i < 14)
	{
		debug_dprintf(STDERR_FILENO, "test case: \"%s\"\n", test_case[i]);
		test(test_case[i]);
		i += 1;
	}
	return (0);
}
