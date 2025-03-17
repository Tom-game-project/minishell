#include "list.h"
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "test_tools.h"
#include "tom_parser.h"

static
bool
is_ifs(char *c)
{
	return (
		*c == ' ' || \
		*c == '\t'|| \
		*c == '\n'
	);
}


/// コマンド文字列をifsで区切り、それ以外はくっつける
///
/// ```
/// [] [" "] []
/// ```
int split_by_ifs(t_str_list **lst, void (*f)(void *))
{
	t_str_list *new_lst;

	new_lst = NULL;
	while (1)
	{
		int index;

		index = str_list_search_index(*lst , is_ifs);
		if (index == -1)
		{ 
			// 見つからなかった場合
			str_list_push(&new_lst, str_list_to_str(*lst));
			str_list_clear(lst, f);
			break;
		}
		else
		{
			t_str_list *tmp;
			// 見つかった場合
			tmp = str_list_cut(lst, index - 1);
			f(str_list_pop(lst, 0));
			str_list_push(&new_lst, str_list_to_str(tmp));
			str_list_clear(&tmp, f);
		}
	}
	str_list_clear(lst, f);
	*lst = new_lst;
	return (0);
}
