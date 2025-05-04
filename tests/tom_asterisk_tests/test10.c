#include "dict.h"
#include "libft.h"
#include <stdlib.h>
#include "exec.h"
#include "list.h"


int test(char *str, t_str_dict *env)
{
	t_str_list *lst;

	lst = expand_env_var(str, env); // 環境変数を考慮した展開
	str_list_print(lst);
	str_list_clear(&lst, free);
	return (0);
}


/// ```bash
/// make test TEST_FILE=tests/tom_asterisk_tests/test10.c
/// ```
int main()
{
	t_str_dict *d;
	char *str = "\"$HELLO\"'$HELLO'$HELLO";

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

	test(str, d);
	str_dict_clear(&d, free, free);
	return (0);
}
