#include "tom_parser.h"
#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/// ```bash
/// make vtest TEST_FILE=tests/tom_parser_test/tom_parser_test00.c
/// ```
int main()
{
	//char *str = "(() && ((echo \"hello world\") && ()))     && \"(hello world\"\"world)\" || ls -la ";
	//char *str = "\"(() && (() &&\" && \"hello world\"";
	//char *str = "(\")\")||hello";
	//char *str = "(\")\")||hello>>";
	char *str = "(\")\")|| hello >> ||";
	t_char_list *lst;
	char *s;
	
	lst = NULL;
	char_list_push_str(&lst, str);
	t_str_list *lexed;
	lexed = NULL;
	while (1)
	{
		t_char_list *head;

		head  = pre_lexer(&lst);
		if (head == NULL)
			break;
		s = char_list_to_str(head);
		char_list_clear(&head);
		str_list_push(&lexed, s);
	}
	ope_collector(&lexed);
	str_list_print(lexed);
	str_list_clear(&lexed, free);
	return (0);
}
