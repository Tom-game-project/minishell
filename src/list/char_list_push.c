#include "list.h"
#include <stdlib.h>
#include "char_list.h"

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
	t_anytype elem;
	elem.c = c;
	return (void_list_push(node, elem));
}

/// char *をstringとして追加する関数
int char_list_push_str(t_char_list **node, char *str)
{	
	while (*str != '\0')
	{
		if (char_list_push(node, *str) == 1)// err
			return (1);
		str++;
	}
	return (0);
}
