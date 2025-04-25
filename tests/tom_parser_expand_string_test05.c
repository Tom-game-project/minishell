#include "exec.h"
#include "libft.h"
#include "list.h"
#include "test_tools.h"
#include <unistd.h>

/// ```bash
/// make test TEST_FILE=tests/tom_parser_expand_string_test05.c
/// ```
int main()
{
	t_str_dict *d;
	t_str_list *lst;
	t_str_list *result_list;
	
	d = NULL;
	str_dict_add(
		&d,
		ft_strdup("HELLO"),
		ft_strdup("hello.c"), 
		free
	);
	str_dict_add(
		&d,
		ft_strdup("$"),
		ft_strdup("PID"), 
		free
	);
	str_dict_add(
		&d,
		ft_strdup("?"),
		ft_strdup("EXIT STATUS"), 
		free
	);

	lst = NULL;
	str_list_push(&lst, ft_strdup("$HELLO\"$HELLO\"'$HELLO'"));
	str_list_push(&lst, ft_strdup("*.c"));
	str_list_push(&lst, ft_strdup("./src/ex*/ex*.c"));
	str_list_print(lst);
	debug_dprintf(STDERR_FILENO, "===========\n");
	result_list = expand_env_vars(lst, d);
	str_list_print(result_list);
	str_list_clear(&result_list, free);
	str_list_clear(&lst, free);
	str_dict_clear(&d, free, free);
	return (0);
}
