
// make vtest TEST_FILE=tests/kaara_parser_test/separate_pipe_test.c

#include "list.h"
#include "parser.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

int main(void)
{
	t_str_list *result;
 	char *input = ft_strdup("< infile | echo world");
	t_ast *ast = allocation_ast();
	printf("%s\n", input);
	result = separate_and_store_pipe_operators(ast, &input);
	str_list_print(result);
    str_list_clear(&result, free);
	printf("%s\n", input);
	return 0;
}