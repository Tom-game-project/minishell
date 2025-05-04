#include "list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>


bool cmp_func(t_anytype a, t_anytype b)
{
	return (a.i32 < b.i32);
}

///
/// ```bash
/// make test TEST_FILE=tests/void_list/tom_void_list_test05.c
/// ```
int main()
{
	t_void_list *a;
	t_void_list *b;
	t_void_list *p;
	
	t_anytype e;

	a = NULL;
	e.i32 = 1;
	void_list_push(&a, e);
	e.i32 = 2;
	void_list_push(&a, e);
	b = NULL;
	e.i32 = 3;
	void_list_push(&b, e);
	e.i32 = 4;
	void_list_push(&b, e);
	while (1)
	{
		p  = cmppop(&a, &b, cmp_func);
		if (p == NULL)
		{
			break;
		}
		printf("[%d] \n", p->ptr.i32);
		free(p);
	}
	return(0);
}
