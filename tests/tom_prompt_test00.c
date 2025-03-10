#include "list.h"

#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

/// ```bash
/// ls -la | make test TEST_FILE=tests/tom_prompt_test00.c
/// ```
int main()
{
	t_char_list *lst;
	char c;
	char *str;

	lst = NULL;
	while (1)
	{
		if(read(STDIN_FILENO ,&c, 1) == 0)
		{
			break;
		}
		char_list_push(&lst, c);
	}
	str = char_list_to_str(lst);
	printf("%s\n", str);
	return (0);
}
