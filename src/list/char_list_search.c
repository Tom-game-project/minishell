#include "list.h"
#include "void_list.h"
#include <stdbool.h>


static bool strip_char(t_anytype elem, bool (*f)(void *))
{
	return (f(&elem.c));
}

int char_list_search_index(t_char_list *node, bool (*f)(char *))
{
	return (
		void_list_search_index(
			node,
			strip_char,
			(t_v2bfunc) f
		)	
	);
}
