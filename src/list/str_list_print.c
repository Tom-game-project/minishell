#include "list.h"
#include <stdlib.h>

#include <stdio.h>

static
int print_string(int index, t_anytype elem)
{
	printf("[%d] \"%s\"\n", index, elem.str);
	return (0);
}


int str_list_print(t_str_list *node)
{
	return (void_list_print(node, print_string));
}
