#include "libft.h"
#include <stdio.h>


/// ```bash
/// make test TEST_FILE=tests/tom_ft_substr_test00.c
/// ```
int main()
{
	char *str = "(hello world)";

	
	printf("\"%s\"\n", ft_substr(str, 1, ft_strlen(str) - 2));
	return (0);
}
