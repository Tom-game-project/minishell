#include "list.h"
#include <stdlib.h>


static void nop(t_anytype a)
{
	(void) a;
}

/// clear
///
int int_list_clear(t_int_list **node)
{
	void_list_clear(node, nop);
	return (0);
}
