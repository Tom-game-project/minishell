#include "list.h"
#include <sched.h>
#include <stdbool.h>
#include <unistd.h>
#include "libft.h"

bool char_list_endswith(t_char_list *lst, char *str)
{
	char *lst_str;
	size_t lst_str_len;
	size_t str_len;
	bool r;

	lst_str = char_list_to_str(lst);
	lst_str_len = ft_strlen(lst_str);
	str_len = ft_strlen(str);
	if (lst_str_len < str_len)
		return (false);
	r = ft_strncmp(lst_str + lst_str_len - str_len, str, str_len) == 0;
	free(lst_str);
	return (r);
}
