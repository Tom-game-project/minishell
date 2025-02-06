#include "list.h"
#include <stdio.h>
#include <stdlib.h>

static void nop(void *a)
{
	(void) a;
}

/// str_list_joinのテスト
///
/// ```bash
/// make vtest TEST_FILE=tests/tom_str_list_test03.c
/// ```
int main()
{
	t_str_list *node;
	char *str;

	node = NULL;
	str_list_push(&node, "hello");
	str_list_push(&node, "world");
	str_list_push(&node, "ara");
	str_list_push(&node, "tsuna");
	str_list_push(&node, "tom");
	str_list_push(&node, "miyuu");
	str_list_push(&node, "yuta");
	
	str = str_list_join(node, "(^_^)");
	printf("joined str \"%s\"\n", str);
	str_list_clear(&node, nop);
	free(str);
	return (0);
}
