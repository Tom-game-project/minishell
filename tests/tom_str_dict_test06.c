#include "dict.h"
#include"libft.h"
#include <stdio.h>
#include <stdlib.h>

/// `envp_to_str_dict`関数のテスト
///
/// 実際に`main`の引数から、`envp`を受け取ってディクショナリを作る
/// ```bash
/// make vtest TEST_FILE=tests/tom_str_dict_test06.c
/// ```
int main(int argc, char *argv[], char *envp[])
{
	(void) argc;
	(void) argv;

	t_str_dict *node;
	t_str_dict *a;
	
	a = NULL;
	envp_to_str_dict(&a, envp);

	node = get_str_dict_by_key(a, "PATH");
	printf("PATH %s\n" , node->value);
	str_dict_clear(&a, free, free);
	return (0);

}
