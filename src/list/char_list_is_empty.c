#include "list.h"
#include <stdbool.h>


bool char_list_is_empty(t_char_list *node)
{
	return (char_list_len(node) == 0);
}

