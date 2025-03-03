#include "list.h"
#include <stdlib.h>
#include <stdbool.h>
#include "void_list.h"

static bool strip_string(t_anytype elem, bool (*f)(void *))
{
	return (f(elem.str));
}

static bool strip_string2(t_anytype elem, bool (*f)(void *, void *), void *str)
{
	return (f(elem.str, str));
}

/// 条件に当てはまった、リストの中の文字列、を探し返す。条件に当てはまる.
char *str_list_search(t_str_list *node, bool (*f)(char *))
{
	t_anytype elem;

	if (void_list_search(
			node,
			strip_string,
			(t_v2bfunc) f,
			&elem
		) == -1)
		return (NULL); // もし何も見つからなかった場合
	return (elem.str);
}

/// 第３引数に渡された引数が、第二引数で渡された関数の第２引数に渡される
///
/// 特定の文字列を探す用途などに使える
t_str_list *str_list_search_node(t_str_list *node, bool (*f)(char *, char *), char *str)
{
	int index;

	index = void_list_search2_index(
		node,
		strip_string2,
		(t_vv2bfunc) f,
		(void *) str
	);
	if (index == -1) // 見つからない場合
		return (NULL);
	return (void_list_get_elem(node, index));
}

/// 条件に当てはまった、リストの中の文字列、を探し返す。条件に当てはまる.
int str_list_search_index(t_str_list *node, bool (*f)(char *))
{
	return (
		void_list_search_index(
			node, 
			strip_string,
			(t_v2bfunc) f
			)
	);
}

