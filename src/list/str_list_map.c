#include "list.h"
#include <stdio.h>
#include <stdlib.h>

/// t_str_listの各要素に対して、関数fを適用する
int str_list_map(t_str_list **node, char *(*f)(char *))
{
	t_str_list *p;

	p = *node;
	while (p != NULL)
	{
		p->str = f(p->str);
		p = p->next;
	}
	return (0);
}


/// t_str_listの各要素に対して、関数fを適用する
/// 適用する関数の第二引数に常に`str_list_map_arg1`が与えられる
int str_list_map_arg1(t_str_list **node, char *(*f)(char *,char *), char *str)
{
	t_str_list *p;

	p = *node;
	while (p != NULL)
	{
		p->str = f(p->str, str);
		p = p->next;
	}
	return (0);
}
