#include "list.h"

char char_list_pop(t_char_list **node, int index)
{
	t_anytype rvalue;
	int err;

	err = void_list_pop(node, index, &rvalue);
	if (err == -1)
		return ('\0');
	else
		return (rvalue.c);
}

