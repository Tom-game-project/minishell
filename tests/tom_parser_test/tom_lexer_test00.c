#include "list.h"
#include "tom_parser.h"

/// ```bash
/// make test TEST_FILE=tests/tom_parser_test/tom_lexer_test00.c
/// ```
int main()
{
	t_str_list *lst;
	lst = lexer("ls -la &&(cat \"hello world\") | \"(\"hello world\")\"");
	str_list_print(lst);
	return (0);
}
