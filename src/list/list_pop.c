#include "list.h"

char	*list_pop(t_list *list, int	n)
{
	int     i;
	char	*str;
	t_list  *head;

	i = 0;
	head = list;
	while (i <= n - 1)
	{
		if (head == NULL)
			return (NULL);
		head = head->next;
		i++;
	}
	str = ft_strdup(head->str);
	return (str);
}
