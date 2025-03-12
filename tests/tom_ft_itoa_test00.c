#include "libft.h"

#include <stdio.h>
#include <stdlib.h>

/// ```bash
/// make vtest TEST_FILE=tests/tom_ft_itoa_test00.c
/// ```
int main ()
{
	char *a;
	a = ft_itoa(1);
	printf("%s \n", a);
	free(a);
	return (0);
}
