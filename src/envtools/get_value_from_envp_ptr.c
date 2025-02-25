#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

/// valueを取得する関数を作る
char *get_value_from_envp_ptr(char *str)
{
	unsigned int s;
	char *str_tmp;

	s = 0;
	str_tmp = str;
	while (*str != '=')
	{
		if (*str == '\0')
			return (NULL);
		s++;
		str++;
	}
	return (ft_substr(str_tmp, s + 1, ft_strlen(str_tmp) - s - 1));
}

