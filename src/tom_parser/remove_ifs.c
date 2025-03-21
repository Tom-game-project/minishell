#include "list.h"
#include <stdlib.h>

static void nop (void *a)
{
	(void) a;
}

int remove_ifs(t_str_list **lst) // 確保された領域なので、freeしてok
{
	t_str_list *ifs_lst;

	if (str_list_len(*lst) == 0)
		return (1);
	ifs_lst = NULL;
	str_list_push(&ifs_lst, " ");
	str_list_push(&ifs_lst, "\t");
	str_list_push(&ifs_lst, "\n");
	str_list_trim(lst, ifs_lst, free);
	str_list_clear(&ifs_lst, nop);
	return (0);
}

