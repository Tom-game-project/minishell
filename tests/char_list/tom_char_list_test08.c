#include "list.h"
#include <stdlib.h>
#include <stdio.h>

/// `char_list_to_str`関数が正しく動作するかの確認
/// 
int main()
{
	t_char_list *a;
	char *str;

	a = NULL;
	char_list_push(&a, 'h');
	char_list_push(&a, 'e');
	char_list_push(&a, 'l');
	char_list_push(&a, 'l');
	char_list_push(&a, 'o');
	printf("len %d\n", char_list_len(a));
	str = char_list_to_str(a);
	printf(
		"str \"%s\"\n",
		str
	);
	char_list_clear(&a);
	free(str);
	return (0);
}
