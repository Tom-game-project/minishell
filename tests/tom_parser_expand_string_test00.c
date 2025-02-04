#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "list.h"
#include "dict.h"



int main()
{
	t_str_list *s;
	char *str = "\"abc'$HELLO'cba\"hello'\"'\"$PATH\"hello'\"aaaa'world $PATH'";

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
