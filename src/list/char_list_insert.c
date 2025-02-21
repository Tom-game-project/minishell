#include <stdlib.h>
#include "char_list.h"
#include "list.h"

#include <stdio.h>

/// @brief 
/// @param node_p 
/// @param index 
/// @param value 
/// @return 
/// 
/// indexは、0から`char_list_len(a) - 1`の範囲に収まる必要がある
///
int	char_list_insert(t_char_list **node, int index, char c)
{
	t_anytype elem;

	elem.c = c;
	return (void_list_insert(node, index, elem));
}

