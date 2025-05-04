#include "list.h"
#include "libft.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

bool cmp(t_anytype a, t_anytype b)
{
	return (a.i32 < b.i32);
}

bool cmp1(t_anytype a, t_anytype b)
{
	return (a.i32 > b.i32);
}



/// 文字列の辞書順比較用の関数
bool cmp_str(t_anytype a, t_anytype b)
{
	char *a_str;
	char *b_str;

	a_str = a.str;
	b_str = b.str;
	while (*a_str != '\0' && *b_str != '\0')
	{
		if (*a_str < *b_str)
		{
			return (true);
		}
		else if (*a_str > *b_str)
		{
			return (false);
		}
		a_str++;
		b_str++;
	}
	return (*a_str < *b_str);
}

/// intのsort
///
int test00()
{
	t_void_list *a;

	a = NULL;
	int_list_push(&a, 0);
	int_list_push(&a, 1);
	int_list_push(&a, 4);
	int_list_push(&a, 5);
	int_list_push(&a, 6);
	int_list_push(&a, 0);
	int_list_push(&a, 3);
	int_list_push(&a, 8);
	int_list_push(&a, 7);
	int_list_push(&a, 2);
	int_list_push(&a, 9);

	printf("cmp1\n");
	merge_sort(&a, cmp1);
	int_list_print(a);

	printf("cmp\n");
	merge_sort(&a, cmp);
	int_list_print(a);

	int_list_clear(&a);
	return (0);
}

int test01()
{
	t_void_list *a;

	a = NULL;
	str_list_push(&a, ft_strdup("hello"));
	str_list_push(&a, ft_strdup("world"));
	str_list_push(&a, ft_strdup("THIS IS TOM."));
	str_list_push(&a, ft_strdup("this is tom"));

	printf("cmp1\n");
	merge_sort(&a, cmp_str);
	str_list_print(a);

	str_list_clear(&a, free);
	return (0);
}

/// sortのテスト
/// ```bash
/// make vtest TEST_FILE=tests/void_list/tom_void_list_test06.c
/// ```
int main()
{
	//test00();
	test01();
}
