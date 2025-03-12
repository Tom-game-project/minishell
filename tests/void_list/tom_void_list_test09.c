#include "list.h"
#include <stdbool.h>
#include <stdio.h>
#include "libft.h"


bool starts_with_hello(
	t_anytype a,
	t_anytype b
)
{
	return (
		ft_strncmp(a.str, b.str, ft_strlen(b.str)) == 0
	);


}


/// ```bash
/// make vtest TEST_FILE=tests/void_list/tom_void_list_test09.c
/// ```
int main()
{
	t_str_list *a;
	t_str_list *b;
	t_anytype s;

	a = NULL;
	str_list_push(&a, ft_strdup("hello world"));
	str_list_push(&a, ft_strdup("h ello world"));
	str_list_push(&a, ft_strdup("hello333 world"));

	s.str = "hello";
	b = void_list_filter2(
		&a,
		starts_with_hello,
		s
	);
	printf("--- a ---\n");
	str_list_print(a);
	printf("--- b ---\n");
	str_list_print(b);

	str_list_clear(&a, free);
	str_list_clear(&b, free);
	return (0);

}
