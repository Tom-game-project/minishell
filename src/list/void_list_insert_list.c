#include "list.h"
#include <stdlib.h>

/// リストの任意の位置に別のリストを挿入する関数
int void_list_insert_list(
	t_void_list **target,
	t_void_list *lst,
       	int index
)
{
	t_void_list *head;
	t_void_list *back;

	head = void_list_cut(target, index);
	if (head == NULL)
		head = lst;
	else{
		back = void_list_get_back(head);
		back->next = lst;
	}
	if (lst != NULL)
	{
		back = void_list_get_back(lst);
		back->next = *target;
	}
	*target = head;
	return (0);
}
