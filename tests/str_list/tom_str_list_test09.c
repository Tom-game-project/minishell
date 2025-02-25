#include "list.h"
#include "libft.h"
#include <stdlib.h>

/// `concat`関数が正しく機能するかのテスト
///
/// ```bash
///  make vtest TEST_FILE=tests/tom_str_list_test09.c
/// ```
int main()
{
	t_str_list *a;
	t_str_list *b;

	a = NULL;
	str_list_push(&a, ft_strdup("1hello"));
	str_list_push(&a, ft_strdup("2hello"));
	str_list_push(&a, ft_strdup("3hello"));
	str_list_push(&a, ft_strdup("4hello"));

	b = NULL;
	str_list_push(&b, ft_strdup("1world"));
	str_list_push(&b, ft_strdup("2world"));
	str_list_push(&b, ft_strdup("3world"));
	str_list_push(&b, ft_strdup("4world"));

	str_list_concat(&a, b);
	str_list_print(a);
	str_list_clear(&a, free);
	/// bはfreeしてはいけない
	return (0);
}
