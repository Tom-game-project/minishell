#include "list.h"
#include <stdlib.h>
#include <stdbool.h>

/// 条件に当てはまったリストの中の要素を探し返す。条件に当てはまる.
/// 
/// 返り値
/// - err(-1)
/// - ok(0)
/// 検索の結果はrvalueに格納される
int void_list_search(
	t_void_list *node,
       	bool (*func)(
		t_anytype,
		bool (*g)(void *)), 
	bool (*f)(void *),
       	t_anytype *rvalue
)
{
	while (node != NULL)
	{
		if (func(node->ptr, f))
		{
			*rvalue = node->ptr;
			return (0);
		}
		node = node->next;
	}
	return (-1);
}

/// 条件に当てはまった、リストの中の文字列、を探し返す。条件に当てはまる.
/// 探すべき条件に当てはまるものが見当たらない場合は-1を返却する
///
/// 返り値
/// - not found (-1)
/// - index(n >= 0)
int void_list_search_index(
	t_void_list *node, 
	bool (*func)(
		t_anytype,
		bool (*g)(void *)),
       	bool (*f)(void *)
)
{
	int i;

	i = 0;
	while (node != NULL)
	{
		if (func(node->ptr, f))
			return (i);
		node = node->next;
		i += 1;
	}
	return (-1);
}

/// 第３引数に渡された引数が、第二引数で渡された関数の第２引数に渡される
///
/// 特定の文字列を探す用途などに使える
///
/// 返り値
/// - not found (-1)
/// - index(n >= 0)
int void_list_search2_index(
	t_void_list *node,
	bool (*func)(
		t_anytype, 
		bool (*g)(void *, void *), 
		void *), 
	bool (*f)(void *, void *),
	void *str
)
{
	int i;

	i = 0;
	while (node != NULL)
	{
		if (
			func(
				node->ptr,
				f,
			       	str
			)
		)
			return (i);
		node = node->next;
		i += 1;
	}
	return (-1);
}

