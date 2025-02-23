#include "libft.h"
#include <stdio.h>

/// ```bash
/// make test TEST_FILE=tests/tom_libft_test00.c
/// ```
int main()
{
	char *a;
	char *b;

	b = ft_strdup("helloo");
	a = ft_strdup("hello");

	if (ft_strncmp(a, b , ft_strlen(a)) == 0 && ft_strncmp(b, a , ft_strlen(b)) == 0)
	{
		printf("一致しました");
	}
	else 
	{
		printf("一致していません");
	}
	return (0);
}
