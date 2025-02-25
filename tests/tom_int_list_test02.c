#include "list.h"
#include <stdio.h>
#include <stdlib.h>


/// `int_list_insert`関数のテスト
/// ```bash
/// make vtest TEST_FILE=tests/tom_int_list_test02.c
/// ```
int main()
{
	t_int_list *a;
	//int i;

	a = NULL;
	int_list_insert(&a, 0, 1);
	int_list_insert(&a, 0, 2);
	int_list_insert(&a, 0, 3);
	int_list_insert(&a, 0, 4);
	printf("length of list %d\n", int_list_len(a));

	//printf(">> [%d] \n", i); // もし空のリストから要素を取り上げると-1が返る
	int_list_print(a);
	int_list_clear(&a);
	return (0);
}
