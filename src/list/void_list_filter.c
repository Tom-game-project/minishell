#include "list.h"
#include <stdlib.h>


/// 
/// 与えられた引数のポインタは、条件に当てはまらなかったものが入る
/// 返り値は、条件に当てはまったもののリスト
/// 
t_void_list *void_list_filter(
	t_void_list **node,
	bool (*f)(t_anytype)
)
{
	t_void_list *t_list;
	t_void_list *f_list;
	t_void_list *tmp;
	t_void_list *p;

	p = *node;
	t_list = NULL;
	f_list = NULL;
	while (p != NULL) 
	{
		tmp = p;
		p = p->next;
		if (f(tmp->ptr))
		{
			tmp->next = NULL;
			void_list_concat(&t_list, tmp);
		}
		else
		{
			tmp->next = NULL;
			void_list_concat(&f_list, tmp);
		}
	}
	*node = f_list;
	return (t_list);
}
