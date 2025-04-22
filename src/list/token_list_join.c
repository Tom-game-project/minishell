#include "list.h"
#include "libft.h"
#include "test_tools.h"
#include <sched.h>
#include <unistd.h>

static size_t check_output_length(t_void_list *lst)
{
	size_t len;

	len = 0;
	while (lst != NULL)
	{
		len += ft_strlen(lst->ptr.ex_token->str);
		lst = lst->next;
	}
	return (len);
	
}

char *token_list_join(t_void_list *lst)
{
	char *str;
	char *ptr;
	char *tmp;

	str = (char *) malloc(sizeof(char) * (check_output_length(lst) + 1));
	tmp = str;
	while (lst != NULL)
	{
		ptr = lst->ptr.ex_token->str;
		while (*ptr != '\0')
		{
			*str = *ptr;
			ptr++;
			str++;
		}
		lst = lst->next;
	}
	*str = '\0';
	return (tmp);
}
