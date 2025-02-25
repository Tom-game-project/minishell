#include "list.h"
#include <stdlib.h>

///
t_int_list *init_int_list(int i)
{
	t_anytype elem;

	elem.i32 = i;
	return (void_list_init(elem));
}
