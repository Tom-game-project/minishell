#include "list.h"
#include "libft.h"

#include <stdlib.h>
#include <stdio.h>

//char *cpy(char *ptr)
//{
//	return (ptr);
//}

/// 所有権の解決
///
/// tom_str_list_test09.cと見比べると良い
/// ```bash
/// make vtest TEST_FILE=tests/tom_str_list_test11.c
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

	/// ここで、bを完全にコピーしたものをくっつける
	str_list_concat(&a, str_list_clone(b, ft_strdup));
	printf("list a\n");
	str_list_print(a);
	/// 
	printf("list b\n");
	str_list_print(b);
	/// 何も考えずどちらもfreeすればいい
	///
	str_list_clear(&a, free);
	str_list_clear(&b, free);
	return (0);

}
