#include "list.h"
#include <stdlib.h>

int void_list_clear(t_void_list **node, void (*f)(t_anytype))
{
	t_void_list *tmp;

	while (*node != NULL)
	{
		tmp = (*node)->next;
		f((*node)->ptr);
		free(*node);
		*node = tmp;
	}
	return (0);
}

/// - node: list本体
/// - func : unionを脱がす関数
/// - f : freeする関数
int void_list_clear_func(t_void_list **node, void (*func)(t_anytype, void (*g)(void *)), void(*f)(void *))
{
	t_void_list *tmp;

	while (*node != NULL)
	{
		tmp = (*node)->next;
		func((*node)->ptr, f);
		free(*node);
		*node = tmp;
	}
	return (0);
}

