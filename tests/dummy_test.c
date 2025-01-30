#include <assert.h>
#include <stdio.h>
#include "built_in.h"

int main()
{
	// return_one_funcが　一を返すかどうかのテスト 
	assert(return_one_func() == 1);
	printf("success!\n");
	// testsの説明
	printf(
		"make testの使い方\n"
		"make test TEST_FILE=<PATH/TO/TEST>\n"
		"<PATH/TO/TEST>は、testsディレクトリ内の任意のファイルを指定する\n"
	);
	return (0);
}
