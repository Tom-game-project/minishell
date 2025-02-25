#include "list.h"

static void nop(t_anytype elem)
{
	(void) elem;
}


/// TODO
int char_list_clear(t_char_list **node)
{
	return (void_list_clear(node, nop));
}
