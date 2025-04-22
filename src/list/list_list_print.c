#include "list.h"
#include "test_tools.h"
#include <stdlib.h>
#include <unistd.h>

int list_list_print(t_void_list *list, int (*print)(int, t_anytype))
{
	int index;

	index = 0;
	while (list != NULL)
	{
		debug_dprintf(STDERR_FILENO, "====== [%d] ======\n", index);
		void_list_print(list->ptr.list, print);
		list = list->next;
		index += 1;
	}
	return (0);
}
