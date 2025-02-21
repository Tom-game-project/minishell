#include "list.h"
#include <stdio.h>

static int
print_int(int index, t_anytype elem)
{
	printf("[%d] [%d]\n", index, elem.i32);
	return(0);
}

int int_list_print(t_int_list *node)
{
	return ( void_list_print(node, print_int));
}
