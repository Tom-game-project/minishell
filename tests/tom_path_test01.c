#include "list.h"
#include "path.h"
#include <stdio.h>

/// 
/// ある要素がリスト内に存在するかを確認する関数のテスト
/// ```bash
/// make test TEST_FILE=tests/tom_path_test01.c
/// ```
int main()
{

	t_str_list *dir_list = get_dir_list("./");
	//if (is_duplicated("outfile", dir_list))
	if (str_list_in("noexist", dir_list))
	{
		printf("file already exist\n" );
	}
	else
	{
		printf("file does not exist\n" );
	}
	str_list_print(dir_list);
	return (0);
}
