#include "libft.h"
#include "list.h"

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

bool start_with_s(char *s)
{
	if (*s == 's')
		return (true);
	else 
		return (false);
}

int main()
{
	char *str;
	t_str_list *a;

	a = NULL;
	str_list_push(&a, ft_strdup("hello1"));
	str_list_push(&a, ft_strdup("hello2"));
	str_list_push(&a, ft_strdup("hello3"));
	str_list_push(&a, ft_strdup("shello4"));

	str = str_list_search(a, start_with_s);
	printf("[%s]\n", str);
	str_list_clear(&a, free);
	return (0);
}
