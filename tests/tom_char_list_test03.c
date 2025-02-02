#include "list.h"
#include <stdlib.h>
#include <stdio.h>

/// insert関数が正常に動作するかのテスト
/// ```bash
/// make test TEST_FILE=tests/tom_char_list_test03.c
/// ```
int main()
{
	t_char_list *a;
	char c;

	a = NULL;
	char_list_insert(&a, 0, 'a');
	char_list_insert(&a, 0, 'b');
	char_list_insert(&a, 0, 'c');
	char_list_insert(&a, 0, 'd');
	// char_list_print(a);
	while ((c = char_list_pop(&a, 0)) != '\0')
		printf("[%c]\n", c);
	return (0);

}
