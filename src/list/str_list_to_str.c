#include "list.h"
#include "libft.h"
#include <stdlib.h>

/// 格納している文字列の長さの合計
int str_list_len_sum(t_str_list *node)
{
	int i;

	i = 0;
	while (node != NULL)
	{
		i += ft_strlen(node->str);
		node = node->next;
	}
	return (i);
}

char *str_list_to_str(t_str_list *node)
{
	char *rstr;
	char *rstr_tmp;
	char *i_str;

	rstr = (char *)malloc(sizeof(char) * (str_list_len_sum(node) + 1));
	if (rstr == NULL)
		return (NULL);
	rstr_tmp = rstr;
	while (node != NULL)
	{
		i_str = node->str;
		while (*i_str != '\0')
		{
			*rstr = *i_str;
			rstr++;
			i_str++;
		}
		node = node->next;
	}
	*rstr = '\0';
	return (rstr_tmp);
}
