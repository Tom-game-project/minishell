#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


static bool is_newline_wrapper(char *s)
{
	return (*s == '\n');
}


/// ```bash
/// make vtest TEST_FILE=tests/char_list/tom_char_list_test10.c
/// ```
int main()
{
	t_char_list *lst;
	char *str;

	lst = NULL;
	char_list_push_str(&lst, "\n\n\nhello world\nT\nhis is Tom.\n");
	while (1)
	{
		t_char_list *b;
		int index = char_list_search_index(lst, is_newline_wrapper);
		if (index == -1)
			break ;
		b = char_list_cut(&lst, index);
		str = char_list_to_str(b);
		char_list_clear(&b);
		printf("cut [%s]\n", str);
		free(str);
	}
	if (char_list_len(lst) != 0)
	{
		str = char_list_to_str(lst);
		printf("cut [%s]\n", str);
		free(str);
	}
	char_list_clear(&lst);
	return (0);
}
