#include "list.h"
#include <stdio.h>
#include <stdlib.h>

static
void nop(void *a)
{
	(void) a;
}


/// # str_list_push関数のテスト
/// ```bash
/// make vtest TEST_FILE=tests/tom_str_list_test00.c
/// ```
int main()
{
	t_str_list *a;
	//char *s;
	a = NULL;
	str_list_push(&a, "hello1");
	str_list_push(&a, "world");
	str_list_push(&a, "apple");
	str_list_push(&a, "orange");
	str_list_print(a);
	printf("len %d\n", str_list_len(a));
	printf("poped %s\n",str_list_pop(&a, 0));
	printf("poped %s\n",str_list_pop(&a, 1));
	printf("hello world\n");
	str_list_print(a);
	printf("len %d\n", str_list_len(a));

	str_list_clear(&a, nop);
	//while ((s = str_list_pop(&a, 0)) != NULL)
	//{
	//	printf("rrr %s\n", s);
	//}
	return (0);
}
