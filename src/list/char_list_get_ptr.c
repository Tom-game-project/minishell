#include "list.h"
#include <stdlib.h>

t_char_list *char_list_get_ptr(t_char_list *head, int index)
{
	return (void_list_get_elem(head, index));
}
