#include "asterisk.h"
#include "list.h"
#include "libft.h"
#include <stdbool.h>
#include <stdlib.h>
#include "path.h"

int main(void)
{
	t_str_list *dir_list;
	t_str_list *after_parse;
	char *input = ft_strdup("src/parser");

	after_parse = NULL;
	asterisk_parser(&after_parse, input);
	str_list_print(after_parse);
	dir_list = get_dir_list(after_parse->ptr.str);
	str_list_print(dir_list);
	str_list_clear(&after_parse, free);
	str_list_clear(&dir_list, free);
	free(input);
	return (0);
}