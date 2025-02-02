#include "list.h"
#include <stdio.h>
#include <stdlib.h>

/// popが正常に動作するかのテスト
int main()
{
	t_char_list *a;
	char c;
	
	a = NULL;
	char_list_push(&a, 'b');
	char_list_push(&a, 'a');
	char_list_push(&a, 'n');
	char_list_push(&a, 'a');
	char_list_push(&a, 'n');
	char_list_push(&a, 'a');

	// char_list_print(a);
	while ((c = char_list_pop(&a, 0)) != '\0')
		printf("[%c]\n", c);
	return (0);
}
