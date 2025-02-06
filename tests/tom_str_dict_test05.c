#include "dict.h"
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

/// str_dict_clearのテスト
///
/// ```bash
/// make vtest TEST_FILE=tests/tom_str_dict_test09.c
/// ```
int main()
{

	t_str_dict *a;
	char **cp;
	char **cp_tmp;

	a = NULL;
	str_dict_add(&a, ft_strdup("tsuna"), ft_strdup("hello"), free);
	str_dict_add(&a, ft_strdup("tom"),   ft_strdup("vim boy"), free);
	str_dict_add(&a, ft_strdup("kaara"), ft_strdup("aaaaa"), free);
	str_dict_add(&a, ft_strdup("miyuu"), ft_strdup("abbbb"), free);
	str_dict_print(a);

	cp = str_dict_to_envp(a);
	cp_tmp = cp;
	while (*cp != NULL)
	{
		printf("-[%s]\n", *cp);
		free(*cp);
		cp++;
	}
	free(cp_tmp);
	str_dict_clear(&a, free, free);
	return (0);
}

