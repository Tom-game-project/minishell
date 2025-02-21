#include "list.h"
#include "path.h"
#include <stdio.h>
#include <stdlib.h>

/// 名前のかぶらないファイル名を生成する関数
/// ```bash
/// make vtest TEST_FILE=tests/tom_path_test02.c
/// ```
int main()
{
	t_str_list *a;
	char *str;

	a = get_dir_list("./");
	str = gen_nondup_name("infile", a);
	printf("generated path %s\n", str);
	free(str);
	str_list_clear(&a, free);
	return (0);
}
