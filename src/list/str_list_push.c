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
	t_anytype elem;

	elem.str = str;
	return (void_list_push(node, elem));
}
