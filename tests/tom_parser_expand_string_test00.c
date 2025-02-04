#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "list.h"
#include "dict.h"
#include "libft.h"

///
///
/// ```
/// make test TEST_FILE=tests/tom_parser_expand_string_test00.c
/// ```
int main()
{
	t_str_list *s;
	t_str_dict *d;

	char *str = "aaa$HELLO'$WORLD'$HELLOaaa";
	d = NULL;
	str_dict_add(
		&d,
		ft_strdup("HELLO"),
		ft_strdup("HELLO_VALUE"), 
		free
	);
	// str_dict_add();
	//s = expand_string("\"  $PATH  \"\"   hello  \"" , NULL);
	s = expand_string(
		str,
		d
	);
	printf("test case [%s]\n", str);
	str_list_print(s);
	str_list_clear(&s, free);
	//printf("hello world\n");
	return (0);
}
