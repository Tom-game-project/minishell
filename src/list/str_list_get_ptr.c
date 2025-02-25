#include "list.h"
#include <stdlib.h>

t_str_list *str_list_get_ptr(t_str_list *head, int index)
{
	return (void_list_get_elem(head, index));
}
