#include "path.h"
#include "dict.h"
#include <stdio.h>
#include <stdlib.h>

/// get_full_path関数をテストします
/// ```bash
/// make test TEST_FILE=tests/tom_get_full_path_test00.c
/// ```
int main(int argc, char *argv[], char *envp[])
{
	(void) argc;
	(void) argv;

	t_str_dict *d;
	t_str_dict *env_path_node;
	char *str;

	d = NULL;
	envp_to_str_dict(&d, envp);
	env_path_node = get_str_dict_by_key(d, "PATH");
	if (env_path_node == NULL)
	{
		printf("環境変数が設定されていません\n");
		return (1);
	}
	else
	{
		// printf("full path %s \n", env_path_node->value);
		//str = get_full_path("python3", env_path_node->value);
		str = get_full_path("python3", "");
		printf("full path -> \"%s\" \n", str);
		free(str);
	}
	str_dict_clear(&d, free, free);
	return (0);
}

