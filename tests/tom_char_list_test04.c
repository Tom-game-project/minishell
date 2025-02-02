#include "list.h"
#include <stdio.h>
#include <stdlib.h>

/// insertが正常に動作するかのテスト
/// ```bash
/// make test TEST_FILE=tests/tom_char_list_test04.c
/// ```
int main()
{
	t_char_list *a;
	char c;

	a = NULL;
	char_list_push_str(&a, "banana");
	char_list_push(&a, ',');
	char_list_push_str(&a, "apple");
	// char_list_print(a);
	
	char_list_insert_str(&a, 0, "hello");
	while ((c = char_list_pop(&a, 0)) != '\0')
		printf("[%c]\n", c);
	return (0);
}
