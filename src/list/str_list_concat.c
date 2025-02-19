#include <stdlib.h>
#include "list.h"
#include "str_list.h"

/// ２つのリストを接続する関数
/// ```
/// a -> (0) -> (1) -> NULL
/// b -> (2) -> (3) -> NULL
/// ```
///
/// `str_list_concat`呼び出し後の状態
///
/// ```
/// a -> (0) -> (1) -> (2) -> (3) -> NULL
/// b -> (2) -> (3) -> NULL
/// ```
/// ## NOTE
/// `*a = NULL`を許容する
/// `*b = NULL`を許容する
///
/// ## 注意
/// `**a = NULL`は許容できない、
/// concatを実行したあと、もともと`b`に入っていたコンテンツは
/// `a`からも`b`からもアクセスできる状態にあり、二重freeのリスクがある
/// 基本的に、この関数を実行したあとは、`b`の使用を避けるべきである
int str_list_concat(t_str_list **a, t_str_list *b)
{
	t_str_list *node;

	if (*a == NULL)
		return (*a = b, 0);
	node = str_list_get_back(*a);
	node->next = b;
	return (0);
}
