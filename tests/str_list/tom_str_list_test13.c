#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "libft.h"

/// ```bash
/// make test TEST_FILE=tests/str_list/tom_str_list_test13.c
/// ```
int main()
{
	t_str_list *a;
	char *str;

	a = NULL;
	str_list_push(&a, ft_strdup("hello1"));
	str_list_push(&a, ft_strdup("hello2"));
	str_list_push(&a, ft_strdup("hello3"));
	str_list_push(&a, ft_strdup("hello4"));
	str_list_push(&a, NULL);
	str_list_push(&a, ft_strdup("hello5"));

	str_list_print(a);
	str = str_list_join(a, "||");
	printf("\"%s\"\n", str);
	str_list_clear(&a, free);
	free(str);
	return (0);
}
