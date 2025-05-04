#include "list.h"
#include "libft.h"
#include "test_tools.h"
#include <unistd.h>


int print_helper(int i, t_anytype elem)
{
	debug_dprintf(STDERR_FILENO, "%d %s\n", i, elem.str);
	return (0);
}

/// ```
/// make test TEST_FILE=tests/list_list/test00.c
/// ```
int main()
{
	t_void_list *vec_vec_str;
	int i;
	i = 0;

	vec_vec_str = NULL;
	while(i < 3)
	{
		t_void_list *vec_str;

		vec_str = NULL;
		str_list_push(&vec_str, ft_strdup("hello"));
		str_list_push(&vec_str, ft_strdup("this"));
		str_list_push(&vec_str, ft_strdup("iss"));
		str_list_push(&vec_str, ft_strdup("Tom"));

		t_anytype elem;
		elem.list = vec_str;
		void_list_push(&vec_vec_str, elem);
		i += 1;
	}
	list_list_print(vec_vec_str, print_helper);
	return (0);
}
