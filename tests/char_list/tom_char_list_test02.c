#include "list.h"
#include <stdio.h>
#include <stdlib.h>

/// popが正常に動作するかのテスト
///
/// ## チェック
/// - leakをしない
/// - 正しくデータが格納されている
///
/// ```bash
/// make vtest TEST_FILE=tests/char_list/tom_char_list_test02.c
/// ```
int main()
{
	t_char_list *a;
	char c;

	a = NULL;
	char_list_push_str(&a, "banana");
	char_list_push(&a, ',');
	char_list_push_str(&a, "apple");
	// char_list_print(a);
	while ((c = char_list_pop(&a, 0)) != '\0')
		printf("[%c]\n", c);
	return (0);
}
