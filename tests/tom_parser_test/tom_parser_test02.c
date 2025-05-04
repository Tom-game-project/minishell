#include <stdlib.h>
#include "tom_parser.h"
#include "libft.h"
#include "list.h"

/// ```make
/// make vtest TEST_FILE=tests/tom_parser_test/tom_parser_test02.c
/// ```
int main()
{
	t_str_list *lst;

	lst = NULL;
	str_list_push(&lst, ft_strdup("ls"));
	str_list_push(&lst, ft_strdup(" "));
	str_list_push(&lst, ft_strdup("-la"));
	str_list_push(&lst, ft_strdup(" "));
	str_list_push(&lst, ft_strdup("\"sr\""));
	str_list_push(&lst, ft_strdup("c"));

	split_by_ifs(&lst, free);
	str_list_print(lst);
	str_list_clear(&lst, free);
	return (0);
}
