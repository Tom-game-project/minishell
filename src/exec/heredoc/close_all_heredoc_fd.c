#include "list.h"
#include <stdio.h>
#include <unistd.h>

/// 数字のリストの中に含まれるfdをすべてcloseして、
/// リストの要素は削除します
int close_all_heredoc_fd(t_int_list **node)
{
	t_anytype rvalue;
	
	while (void_list_pop(node , 0, &rvalue) != -1)
	{
		close(rvalue.i32);
	}
	int_list_clear(node);
	return (0);
}
