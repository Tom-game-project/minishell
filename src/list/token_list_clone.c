#include "list.h"
#include <stdlib.h>


t_void_list *token_list_clone(t_void_list *lst, t_anytype (*f)(t_anytype))
{
	t_void_list *rlst;

	rlst = NULL;
	while (lst != NULL)
	{
		void_list_push(&rlst, f(lst->ptr));
		lst = lst->next;
	}
	return (rlst);
}
