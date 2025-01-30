#include <assert.h>
#include <stdio.h>
#include "built_in.h"

int main()
{
	// return_one_funcが　一を返すかどうかのテスト 
	assert(return_one_func() == 1);
	printf("success!\n");
	return (0);
}
