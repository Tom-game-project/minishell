#include "dict.h"
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

/// str_dict_lenのテスト
///
/// ```bash
/// make vtest TEST_FILE=tests/tom_str_dict_test04.c
/// ```
int main()
{

	t_str_dict *a;

	a = NULL;
	str_dict_add(&a, ft_strdup("tsuna"), ft_strdup("hello"), free);
	str_dict_add(&a, ft_strdup("tom"),   ft_strdup("vim boy"), free);
	str_dict_add(&a, ft_strdup("kaara"), ft_strdup("aaaaa"), free);
	str_dict_add(&a, ft_strdup("miyuu"), ft_strdup("abbbb"), free);

	printf("dict len %d \n", str_dict_len(a));
	str_dict_clear(&a, free, free);
	printf("dict len %d \n", str_dict_len(a));
	return (0);
}

