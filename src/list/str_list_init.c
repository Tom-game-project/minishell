#include "list.h"
#include <stdlib.h>

/**
 * pub init_char_list
 * @brief free: required
 *
 */
t_str_list *init_str_list(char *str)
{
	t_str_list	*node;

	node = (t_str_list *)malloc(sizeof(t_str_list));
	if (node == NULL)
		return (NULL);
	node->next = NULL;
	node->str = str;
	return (node);
}
