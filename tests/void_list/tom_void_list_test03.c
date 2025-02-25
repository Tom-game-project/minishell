#include "list.h"
#include <stdlib.h>
#include <stdio.h>

/// 様々な型を許容するための妥協案

static int print_str(int index, t_anytype elem)
{
	// unsafe
	return (printf("[%d] %d\n", index, elem.i32));
}


static void nop(t_anytype a)
{
	(void) a;
}

/// ```bash
/// make test TEST_FILE=tests/tom_void_list_test03.c
/// ```
int main()
{
	t_void_list *a;
	t_anytype elem;

	a = NULL;

	elem.i32 = 0;
	void_list_push(&a, elem);
	elem.i32 = 1;
	void_list_push(&a, elem);
	elem.i32 = 2;
	void_list_push(&a, elem);
	elem.i32 = 3;
	void_list_push(&a, elem);

	elem.i32 = 100;
	void_list_insert(&a, 2, elem);
	printf("length of list %d \n", void_list_len(a));

	//printf(
	//	"[1] %d\n",
	//	void_list_get_elem(a, 1)->ptr.i32
	//);
	void_list_print(a, print_str);
	void_list_clear(&a, nop);
	return (0);

}
