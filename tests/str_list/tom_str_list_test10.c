#include "list.h"
#include "libft.h"
#include <stdlib.h>


int main()
{
	t_str_list *a; // コピー元:W
	t_str_list *b; // copy先

	a = NULL;
	str_list_push(&a, ft_strdup("1hello world"));
	str_list_push(&a, ft_strdup("2hello world"));
	str_list_push(&a, ft_strdup("3hello world"));
	str_list_push(&a, ft_strdup("4hello world"));

	b = str_list_clone(a, ft_strdup);

	str_list_print(b);
	str_list_clear(&a, free);
	str_list_clear(&b, free);
	return (0);
}
