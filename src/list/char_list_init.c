#include "list.h"
#include <stdlib.h>

/**
 * pub init_char_list
 * @brief free: required
 *
 */
t_char_list *init_char_list(char c)
{
	t_char_list	*node;

	node = (t_char_list *)malloc(sizeof(t_char_list));
	if (node == NULL)
		return (NULL);
	node->next = NULL;
	node->data = c;
	return (node);

}
