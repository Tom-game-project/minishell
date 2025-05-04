#include "list.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


static bool includes_newline(char *str)
{
	while (*str != '\0')
	{
		if (*str == '\n')
			return (true);
		str++;
	}
	return (false);
}

static bool over_100_chars(char *str)
{
	return (ft_strlen(str) > 12);
}

/// str_list_cut関数のテスト
///
/// ```bash
///
/// make vtest TEST_FILE=tests/tom_str_list_test12.c
/// ```
int main()
{
	t_str_list *a;
	t_str_list *b;

	a = NULL;
	str_list_push(&a, ft_strdup("0hello world"));
	str_list_push(&a, ft_strdup("1hello world"));
	str_list_push(&a, ft_strdup("2hello world\n"));
	str_list_push(&a, ft_strdup("3hello world"));
	str_list_push(&a, ft_strdup("4hello world"));

	printf("search new line %d\n", str_list_search_index(a, includes_newline));
	printf("search over 100 chars %d\n", str_list_search_index(a, over_100_chars));
	b = str_list_cut(&a, 4);

	printf("list a\n");
	str_list_print(a);

	printf("list b\n");
	str_list_print(b);

	str_list_clear(&a, free);
	str_list_clear(&b, free);
	return (0);
}
