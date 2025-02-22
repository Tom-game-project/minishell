#include "list.h"

/// この関数は一般性を失っている、
/// 空のlistからpopした場合にしてほしい挙動は、
/// 実装によって違う
/// この関数は、fdを扱うことを主たる目的として想定するため
/// 空のリストからpopした結果を
/// - err(-1)
/// として扱う
///
int int_list_pop(t_int_list **node, int index)
{
	t_anytype rvalue;
	int err;

	err = void_list_pop(node, index, &rvalue);
	if (err == -1)
		return (-1); // 要素が存在しなかった場合
	else
		return (rvalue.i32);
}
