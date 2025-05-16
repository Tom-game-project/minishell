#include "list.h"
#include <stdlib.h>

/// pushができているかどうか
///
/// ## チェック
/// - leakをしない
/// - 正しくデータが格納されている
///
/// ```bash
/// make vtest TEST_FILE=tests/char_list/tom_char_list_test00.c
/// ```
int main ()
{
	t_char_list *a;
	
	a = NULL;
	char_list_push(&a, 'b');
	char_list_push(&a, 'a');
	char_list_push(&a, 'n');
	char_list_push(&a, 'a');
	char_list_push(&a, 'n');
	char_list_push(&a, 'a');
	char_list_print(a);
	char_list_clear(&a);
	return (0);
}
