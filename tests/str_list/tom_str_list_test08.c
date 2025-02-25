#include "libft.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

/// str_list_get_elem関数のテスト
/// ```
/// make test TEST_FILE=tests/tom_str_list_test08.c
/// ```
int main()
{
	char *str;
	t_str_list *a;

	a = NULL;
	str_list_push(&a, ft_strdup("hello"));
	str_list_push(&a, ft_strdup("world"));
	str = str_list_get_elem(a, 0);

	printf("%s\n", str);
	str_list_clear(&a, free);
	return (0);
}
