#include "list.h"
#include "str_list.h"
#include <stdlib.h>

/** 
 * pub char_list_push
 * 
 * @brief free: required (depend on \`init_node\` function)
 * @param parent_p
 * @param i32_data 
 * @return
 */
int str_list_push(t_str_list **node, char *str)
{
	t_str_list	*back_node_p;
	t_str_list	*new_node_p;

	new_node_p = init_str_list(str);
	if (new_node_p == NULL)
		return (1);
	back_node_p = str_list_get_back(*node);
	if (back_node_p == NULL)
	{
		*node = new_node_p;
		return (0);
	}
	back_node_p->next = new_node_p;
	return (0);
}
