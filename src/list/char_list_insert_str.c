#include "stdlib.h"
#include "list.h"
#include "char_list.h"


/// indexは、0から`char_list_len(a)`の範囲に収まる必要がある
int char_list_insert_str(t_char_list **node, int index,char *str)
{
	t_char_list	*target_node;
	t_char_list	*new_node_last;
	t_char_list	*start_node;
	t_char_list	*str_list;

	target_node = char_list_get_ptr(*node, index);
	str_list = NULL;
	char_list_push_str(&str_list, str);
	if (str_list == NULL)
		return (1);
	new_node_last = char_list_get_back(str_list);
	new_node_last->next = target_node;
	if (0 < index)
	{
		start_node = char_list_get_ptr(*node, index - 1);
		start_node->next = str_list;
	}
	else
		*node = str_list;
	return (0);
}
