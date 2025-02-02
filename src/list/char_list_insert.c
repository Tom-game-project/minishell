#include <stdlib.h>
#include "char_list.h"
#include "list.h"

#include <stdio.h>

/// @brief 
/// @param node_p 
/// @param index 
/// @param value 
/// @return 
/// 
/// indexは、0から`char_list_len(a) - 1`の範囲に収まる必要がある
///
int	char_list_insert(t_char_list **node, int index, char c)
{
	t_char_list	*target_node;
	t_char_list	*new_node;
	t_char_list	*start_node;

	target_node = get_ptr(*node, index);
	new_node = init_char_list(c);
	if (new_node == NULL)
		return (1);
	new_node->next = target_node;
	if (0 < index)
	{
		start_node = get_ptr(*node, index - 1);
		start_node->next = new_node;
	}
	else
		*node = new_node;
	return (0);
}

