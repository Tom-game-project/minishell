#include "dict.h"
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

/// str_dict_clearのテスト
///
/// ```bash
/// make vtest TEST_FILE=tests/tom_str_dict_test03.c
/// ```
int main()
{

	t_str_dict *a;

	a = NULL;
	str_dict_add(&a, ft_strdup("tsuna"), ft_strdup("hello"), free);
	str_dict_add(&a, ft_strdup("tom"),   ft_strdup("vim boy"), free);
	str_dict_add(&a, ft_strdup("kaara"), ft_strdup("aaaaa"), free);
	str_dict_add(&a, ft_strdup("miyuu"), ft_strdup("abbbb"), free);
	str_dict_print(a);

	str_dict_clear(&a, free, free);
	return (0);
}
