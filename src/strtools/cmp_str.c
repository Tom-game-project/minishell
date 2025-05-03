#include "list.h"
#include <stdbool.h>

/// 文字列の辞書順比較用の関数
bool	cmp_str(t_anytype a, t_anytype b)
{
	char	*a_str;
	char	*b_str;

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
