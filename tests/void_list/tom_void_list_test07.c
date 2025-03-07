#include "list.h"
#include <stdlib.h>

/// ```bash
/// make test TEST_FILE=tests/void_list/tom_void_list_test07.c
/// ```
int main()
{
	t_char_list *a;

	a = NULL;
	char_list_push(&a, 'a');
	char_list_push(&a, 'b');
	char_list_push(&a, 'c');
	char_list_push(&a, 'd');
	char_list_push(&a, 'e');
	char_list_push(&a, 'f');


	t_char_list *b;
	b = NULL;
	char_list_push(&b, '1');
	char_list_push(&b, '2');
	char_list_push(&b, '3');

	void_list_insert_list(&a, b, 0);
	char_list_print(a);
	char_list_clear(&a);
	return(0);
}
