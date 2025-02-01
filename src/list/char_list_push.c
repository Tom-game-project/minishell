#include "list.h"
#include <stdlib.h>


/**
 * private get_back
 * @brief free: not required
 */
static t_char_list *get_back(t_char_list *node)
{
	if (node == NULL)
		return (node);
	while (node -> next != NULL)
		node = node->next;
	return (node);
}

/** 
 * pub char_list_push
 * 
 * @brief free: required (depend on \`init_node\` function)
 * @param parent_p
 * @param i32_data 
 * @return
 */
int char_list_push(t_char_list **node, char c)
{
	t_char_list	*back_node_p;
	t_char_list	*new_node_p;

	new_node_p = init_char_list(c);
	if (new_node_p == NULL)
		return (1);
	back_node_p = get_back(*node);
	if (back_node_p == NULL)
	{
		*node = new_node_p;
		return (0);
	}
	back_node_p->next = new_node_p;
	return (0);

}

int char_list_push_str(t_char_list **node, char *str)
{	
	while (*str == '\0')
	{
		if (char_list_push(node, *str) == 1)// err
			return (1);
		str++;
	}
	return (0);
}
