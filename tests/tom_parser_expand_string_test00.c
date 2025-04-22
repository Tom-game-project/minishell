#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

#include "expand_string.h"

#include "list.h"
#include "dict.h"
#include "test_tools.h"

int
print_token_list_node(int index, t_anytype token)
{
	(void) index;
	if (token.ex_token->token_type == e_word)
	{
		return (debug_dprintf(STDERR_FILENO, "[e_word] %s\n", token.ex_token->str));
	}
	else 
	{
		return (debug_dprintf(STDERR_FILENO, "[e_asterisk] %s\n", token.ex_token->str));
	}
}
///
///
/// ```
/// make test TEST_FILE=tests/tom_parser_expand_string_test00.c
/// ```
int main()
{
	t_str_list *s;
	t_str_dict *d;

	//char *str = "aaa$HELLO'$WORLD'$HELLOaaa|aaa";
	//char *str = "aaa'$WORLD'$HELLOaaa";
	//char *str = "---\"\"\"'$HELLO*'\"\"\"---*/";
	char *str = "\"*\"*'*'";
	//char *str = "???$HELLO$$?$?HELLO$?$WO";
	//char *str = "$$$";
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
	// str_dict_add();
	//s = expand_string("\"  $PATH  \"\"   hello  \"" , NULL);
	s = expand_string2list2(
		str,
		d
	);
	printf("test case [%s]\n", str);
	//str_list_print(s);
	void_list_print(s, print_token_list_node);
	//str_list_clear(&s, free);
	str_dict_clear(&d, free, free);
	//printf("hello world\n");
	return (0);
}
