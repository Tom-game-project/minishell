#include "libft.h"
#include "list.h"

#include <stdio.h>
#include <stdlib.h>

char *join_func(char *a)
{
	char *rstr;
	
	rstr = ft_strjoin(a, " world");
	free(a);
	return (rstr);
}

/// str_list_map関数をテストする関数
///
int main()
{
	t_str_list *a;

	a = NULL;
	str_list_push(&a, ft_strdup("hello1"));
	str_list_push(&a, ft_strdup("hello2"));
	str_list_push(&a, ft_strdup("hello3"));
	str_list_push(&a, ft_strdup("hello4"));

	str_list_map(&a, join_func);
	str_list_print(a);
	str_list_clear(&a, free);
	return (0);
}
