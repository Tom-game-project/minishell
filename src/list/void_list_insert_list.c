#include "list.h"
#include <stdlib.h>

/// リストの任意の位置に別のリストを挿入する関数
///
/// アロケーションを発生させない
int void_list_insert_list(
	t_void_list **target,
	t_void_list *lst,
       	int index
)
{
	t_void_list *head;

	head = void_list_cut(target, index);
	if (head == NULL)
		head = lst;
	else
		void_list_concat(&head, lst);
	if (lst != NULL)
		void_list_concat(&lst, *target);
	*target = head;
	return (0);
}
