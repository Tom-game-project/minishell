#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

#include "expand_string.h"

#include "dict.h"

///
///
/// ```
/// make test TEST_FILE=tests/tom_parser_expand_string_test03.c
/// ```
int main()
{
	char *rstr;
	t_str_dict *d;

	//char *str = "aaa$HELLO'$WORLD'$HELLOaaa|aaa";
	//char *str = "aaa'$WORLD'$HELLOaaa";
	char *str = "---\"\"\"'$HELLO'\"\"\"---";
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
	rstr = heredoc_expand_string(
		str,
		d
	);
	printf("test case [%s]\n", str);
	printf("%s\n", rstr);
	free(rstr);
	str_dict_clear(&d, free, free);
	//printf("hello world\n");
	return (0);
}
