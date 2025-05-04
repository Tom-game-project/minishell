#include "list.h"
#include <stdlib.h>
#include <stdio.h>



/// headからとりだす関数がうまく言っているかどうかを確かめる関数
///
/// ```bash
/// make vtest TEST_FILE=tests/void_list/tom_void_list_test04.c
/// ```
///
///hello world0
/// hello world1
/// hello world2
int main()
{
	t_void_list *a;
	t_void_list *p;
	t_anytype t;
	char *str;

	a = NULL;
	t.str = "hello world0";
	void_list_push(&a, t);
	t.str = "hello world1";
	void_list_push(&a, t);
	t.str = "hello world2";
	void_list_push(&a, t);
	
	while (1)
	{
		p = pop_head_element(&a);
		if (p == NULL)
		{
			break;
		}
		str = p->ptr.str;
		printf("%s\n", str);
		free(p);
	}
	return (0);
}
