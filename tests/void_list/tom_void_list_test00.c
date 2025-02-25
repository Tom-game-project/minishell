#include "list.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int print_str(int index, t_anytype elem)
{
	// unsafe
	return (printf("[%d] %s\n", index, elem.str));
}


static void free_str(t_anytype elem)
{
	free(elem.str);
}

/// ```bash
/// make vtest TEST_FILE=tests/tom_void_list_test00.c
/// ```
int main()
{
	t_void_list *a;
	t_anytype elem;

	//	t_void_list *b;

	a = NULL;
	printf("sizeof void pointer str%ld \n", sizeof(void *));
	printf("sizeof void pointer str%ld \n", sizeof(int));
	elem.str =ft_strdup("0hello world");
	void_list_push(&a, elem);
	elem.str =ft_strdup("1hello world");
	void_list_push(&a, elem);
	elem.str =ft_strdup("2hello world");
	void_list_push(&a, elem);
	printf("length of list %d \n", void_list_len(a));
	void_list_print(a, print_str);
	void_list_clear(&a, free_str);
	return (0);
}

