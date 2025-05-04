#include "list.h"
#include "libft.h"
#include "test_tools.h"
#include <unistd.h>
#include <stdlib.h>

int print_helper(int i, t_anytype elem)
{
	debug_dprintf(STDERR_FILENO, "%d %s\n", i, elem.str);
	return (0);
}

void free_vec_vec_str(t_anytype elem)
{
	(void) elem;
}

/// ```
/// make test TEST_FILE=tests/list_list/test01.c
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
	debug_dprintf(STDERR_FILENO, "============\n");
	
	t_str_list *str_list;
	str_list = list_list_all_concat(vec_vec_str);
	str_list_print(str_list);
	str_list_clear(&str_list, free);
	void_list_clear(&vec_vec_str, free_vec_vec_str);
	return (0);
}

