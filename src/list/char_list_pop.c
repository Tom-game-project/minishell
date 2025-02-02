#include "list.h"
#include "char_list.h"
#include <stdlib.h>

/**
 * pub pop_elem
 * @brief free:required
 * @param node_p_p
 */
t_char_list	*pop_elem(t_char_list **node_p_p)
{
	t_char_list	*head_p;

	head_p = *node_p_p;
	if (head_p == NULL)
		return (NULL);
	*node_p_p = head_p->next;
	if (head_p -> next != NULL)
	{
		head_p->next = NULL;
	}
	return (head_p);
}

/// @brief you must free returned object by yourself
///        values outside the range are undefined
/// @param node_p_p
/// @param index
/// @return
t_char_list	*pop_index_elem(t_char_list **node_p_p, int index)
{
	t_char_list	*r_node;
	t_char_list	*first_node;

	if (index == 0)
		return (pop_elem(node_p_p));
	first_node = *node_p_p;
	r_node = get_raw_ptr(node_p_p, index);
	r_node->next = NULL;
	*node_p_p = first_node;
	return (r_node);
}

char char_list_pop(t_char_list **node, int index)
{
	int		rvalue;
	t_char_list	*head_p;

	if (index < 0 && char_list_len(*node) <= index)
		return ('\0');
	head_p = pop_index_elem(node, index);
	if (head_p == NULL)
		return ('\0');
	rvalue = head_p->data;
	free(head_p);
	return (rvalue);
}

