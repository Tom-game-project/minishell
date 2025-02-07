#include "dict.h"
#include <stdlib.h>
#include "libft.h"

/// str_dict_remove関数のテスト
///
/// ```bash
/// make vtest TEST_FILE=tests/tom_str_dict_test07.c
/// ```
int main()
{
	t_str_dict *a;

	a = NULL;
	str_dict_add(&a, ft_strdup("first"), ft_strdup("hello"), free);
	str_dict_add(&a, ft_strdup("tsuna"), ft_strdup("hello"), free);
	str_dict_add(&a, ft_strdup("tom"),   ft_strdup("vim boy"), free);
	str_dict_add(&a, ft_strdup("kaara"), ft_strdup("aaaaa"), free);
	str_dict_add(&a, ft_strdup("miyuu"), ft_strdup("abbbb"), free);

	str_dict_remove(&a, "tom", free, free);
	str_dict_remove(&a, "tom", free, free);// もし無いものを消しても何もおきない
	str_dict_remove(&a, "first", free, free);// もし無いものを消しても何もおきない
	
	str_dict_print(a);
	str_dict_clear(&a, free, free);
	return (0);
}
