#include "list.h"
#include <stdlib.h>


/// `char_list_clear`関数のテスト
int main()
{
	t_char_list *a;

	a = NULL;
	char_list_push(&a, 'h');
	char_list_push(&a, 'e');
	char_list_push(&a, 'l');
	char_list_push(&a, 'l');
	char_list_push(&a, 'o');
	char_list_clear(&a);

	char_list_push(&a, 'w');
	char_list_push(&a, 'o');
	char_list_push(&a, 'r');
	char_list_push(&a, 'l');
	char_list_push(&a, 'd');
	char_list_print(a);
	char_list_clear(&a);
	return (0);
}
