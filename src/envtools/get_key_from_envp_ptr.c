#include "libft.h"

/// 文字列から、環境変数のidentifierを見つける
char *get_key_from_envp_ptr(char *str)
{
	unsigned int l;
	char *str_tmp;

	l = 0;
	str_tmp = str;
	while (*str != '=')
	{
		if (*str == '\0')
			break ;
		l++;
		str++;
	}
	return (ft_substr(str_tmp, 0, l));
}

