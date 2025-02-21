#include "list.h"
#include <stdlib.h>

/**
 * pub init_char_list
 * @brief free: required
 *
 */
t_char_list *init_char_list(char c)
{
	t_anytype elem;

	elem.c = c;
	return (void_list_init(elem))
		;
}
