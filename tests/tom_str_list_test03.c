#include "list.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static void nop(void *a)
{
	(void) a;
}

int test00()
{
	t_str_list *node;
	char *str;

	node = NULL;
	str_list_push(&node, ft_strdup("hello"));
	str_list_push(&node, ft_strdup("world"));
	str_list_push(&node, ft_strdup("ara"));
	str_list_push(&node, ft_strdup("tsuna"));
	str_list_push(&node, ft_strdup("tom"));
	str_list_push(&node, ft_strdup("miyuu"));
	str_list_push(&node, ft_strdup("yuta"));

	str = str_list_join(node, "(^_^)");
	str_list_print(node);
	printf("joined str \"%s\"\n", str);
	str_list_clear(&node, free);
	free(str);
	return (0);
}

int test01()
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
	str_list_print(node);
	printf("joined str \"%s\"\n", str);
	str_list_clear(&node, nop);
	free(str);
	return (0);
}

/// str_list_joinのテスト
///
/// ```bash
/// make vtest TEST_FILE=tests/tom_str_list_test03.c
/// ```
int main()
{
	test00();
	test01();
	return (0);
}
