#include "strtools.h"
#include "list.h"
#include "libft.h"
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

// 2 ^ 8 = 32
#define HIDE_NAME_LENGTH 8

/// 与えられた32bit整数を16進数に変換して、それを渡された文字列配列にセットする
static int 
u32tostr(char *dst, unsigned int n)
{
	int i;

	i = 0;
	while (i < HIDE_NAME_LENGTH)
	{
		dst[HIDE_NAME_LENGTH - i  - 1] = "0123456789abcdef"[n % 0x10];
		n /= 0x10;
		i += 1;
	}
	return (0);
}

/// 重複しない名前を生成する関数
char *gen_nondup_name(char *basename, t_str_list *dir_lisr)
{
	char a[HIDE_NAME_LENGTH];
	unsigned int i;
	char *rstr;

	i = 0;
	while (i <= UINT_MAX)
	{
		u32tostr(a, i);
		rstr = ft_strjoin(basename, a);
		if (!str_list_in(rstr, dir_lisr))
			// もし重複していなければ
			return (rstr);
		free(rstr);
		i += 1;
	}
	return (NULL);
}
