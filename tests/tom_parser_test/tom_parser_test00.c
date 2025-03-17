#include "tom_parser.h"
#include "list.h"
#include <stdlib.h>
#include <assert.h>

/// ```bash
/// make vtest TEST_FILE=tests/tom_parser_test/tom_parser_test00.c
/// ```
int main()
{
	//char *str = "(() && ((echo \"hello world\") && ()))     && \"(hello world\"\"world)\" || ls -la ";
	//char *str = "\"(() && (() &&\" && \"hello world\"";
	//char *str = "(\")\")||hello";
	char *str = "(\")\")||\"'\"'\"'";
	//char *str = "(\")\")||hello>>";
	//char *str = "(\")\")|| hello >> ||";

	t_str_list *lexed;
	lexed  = lexer(str);
	str_list_print(lexed);
	str_list_clear(&lexed, free);
	return (0);
}
