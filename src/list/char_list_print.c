#include "list.h"
#include <stdio.h>


int
print_char(int index, t_anytype elem)
{
	printf("[%d] [%c]\n", index, elem.c);
	return (0);
}

int char_list_print(t_char_list *node)
{
	return (void_list_print(node, print_char));
}
