#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "list.h"
#include "dict.h"


///
///
/// ```
/// make test TEST_FILE=tests/tom_parser_expand_string_test00.c
/// ```
int main()
{
	t_str_list *s;
	char *str = "aaa$HELLO'$WORLD'$HELLOaaa";

	//s = expand_string("\"  $PATH  \"\"   hello  \"" , NULL);
	s = expand_string(
		str,
		NULL
	);
	printf("test case [%s]\n", str);
	str_list_print(s);
	//printf("hello world\n");
	return (0);
}
