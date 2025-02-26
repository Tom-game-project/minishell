#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

#include "expand_string.h"

#include "list.h"
#include "dict.h"

typedef char *(*sd2cfunc)(char *, void *);

char *
expand_string_wrap_str_free(char *str, t_str_dict *d)
{
	char *rstr;

	rstr = expand_string(str, d);
	free(str);
	return (rstr);
}


///
///
/// ```
/// make vtest TEST_FILE=tests/tom_parser_expand_string_test01.c
/// ```
int main()
{
	t_str_dict *d;
	t_str_list *args;

	args = NULL;
	str_list_push(&args, ft_strdup("aaa$HELLO'$WORLD'$HELLOaaa|aaa"));
	str_list_push(&args, ft_strdup("aaa'$WORLD'$HELLOaaa"));
	str_list_push(&args, ft_strdup("---\"\"\"'$HELLO'\"\"\"---"));
	str_list_push(&args, ft_strdup("???$HELLO$$?$?HELLO$?$WO"));
	str_list_push(&args, ft_strdup("$$$$"));

	d = NULL;
	// 環境変数を模したもの
	str_dict_add(
		&d,
		ft_strdup("HELLO"),
		ft_strdup("HELLO_VALUE"), 
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

	str_list_map_arg1(&args, (sd2cfunc) expand_string_wrap_str_free, d);
	str_dict_clear(&d, free, free);
	str_list_print(args);
	str_list_clear(&args, free);
	return (0);
}
