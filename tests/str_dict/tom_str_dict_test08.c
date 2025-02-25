#include "dict.h"
#include <stdio.h>
#include <stdlib.h>



/// `envp_to_str_dict`関数のテスト
/// `str_dict_to_env`関数のテスト
///
/// 環境変数を標準出力する例
/// 実際に`main`の引数から、`envp`を受け取ってディクショナリを作る
/// ```bash
/// make vtest TEST_FILE=tests/tom_str_dict_test08.c
/// ```
int main(int argc, char *argv[], char *envp[])
{
	(void) argc;
	(void) argv;
	char **envp_sub;
	int i;

	t_str_dict *node;
	t_str_dict *a;
	
	a = NULL;
	envp_to_str_dict(&a, envp);

	node = get_str_dict_by_key(a, "PATH");
	printf("PATH %s\n" , node->value);
	envp_sub = str_dict_to_envp(node);
	i = 0;
	while (envp_sub[i] != NULL)
	{
		printf("%s\n", envp_sub[i]);
		i += 1;
	}

	// clear envp sub
	i = 0;
	while (envp_sub[i] != NULL) {
		free(envp_sub[i]);
		i += 1;
	}
	free(envp_sub);
	str_dict_clear(&a, free, free);
	return (0);

}
