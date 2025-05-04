#include "strtools.h"
#include "libft.h"
#include <stdio.h>

int
test_case(char *str)
{
	char *a; 
	char *b;

	a = ft_strdup(str);
	b = remove_quotations(a);
	printf("[%s] -> [%s]\n", a, b);
	free(a);
	free(b);
	return (0);
}

/// ```bash
/// make vtest TEST_FILE=tests/tom_remove_quotation.c
/// ```
int main()
{
	test_case("hello world");
	test_case("\"hello world\"");
	test_case("'hello world'");
	test_case("\"\"hello world");
	test_case("''hello world");
	test_case("'''hello world");
	test_case("\"\"\"hello world");
	return (0);
}

