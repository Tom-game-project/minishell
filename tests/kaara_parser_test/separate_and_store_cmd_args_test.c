

// make vtest TEST_FILE=tests/kaara_parser_test/separate_and_store_cmd_args_test.c

#include "list.h"
#include "parser.h"
#include "libft.h"
#include <stdio.h>
#include "parser.h"

int main(void)
{
	t_str_list *result;
 	char *input = ft_strdup("kaaara hello");
	t_ast *ast = allocation_ast();
	result = separate_and_store_pipe_operators(ast, &input);
	str_list_print(result);
	printf("%s\n", input);
	return 0;
}