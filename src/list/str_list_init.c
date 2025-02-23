#include "list.h"
#include <stdlib.h>

/**
 * pub init_char_list
 * @brief free: required
 *
 */
t_str_list *init_str_list(char *str)
{
	t_anytype elem;

	elem.str = str;
	return (void_list_init(elem));
}
