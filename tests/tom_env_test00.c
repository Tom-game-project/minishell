#include "dict.h"
#include "built_in.h"
#include <stdio.h>
#include <stdlib.h>


/// built_in_env関数のテスト
///
/// ```bash
/// make test TEST_FILE=tests/tom_env_test00.c
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
	built_in_env(str_dict_to_envp(node));
	str_dict_clear(&a, free, free);
	
	return (0);
}
