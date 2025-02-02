#include "list.h"
#include <stdlib.h>

t_char_list	*get_raw_ptr(t_char_list **node_p_p, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		i += 1;
		if (*node_p_p == NULL)
			return (NULL);
		*node_p_p = (*node_p_p)->next;
	}
	return (*node_p_p);
}


t_char_list *get_ptr(t_char_list *head, int index)
{
	t_char_list *tmp;
	int c;
	
	c= 0;
	tmp = head;
	while (tmp != NULL)
	{
		if (index == c)
			return (tmp);
		tmp = tmp->next;
		c += 1;
	}
	return (NULL);
}
