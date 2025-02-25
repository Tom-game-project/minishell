#include "list.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

/// remove_char_from_split_string
/// 文字列をトリミングし、区切り文字を取り除く
///
static char *remove_char_from_split_string(char *str_tmp, size_t s, size_t l, char c)
{
	char *str;
	char *rstr;
	char set[2];

	set[0] = c;
	set[1] = '\0';
	str = ft_substr(str_tmp, s, l);
	if (str == NULL)
		return (NULL);
	rstr = ft_strtrim(str, set);
	free(str);
	return (rstr);
}

/// 文字ごとに区切って新しいstringのリストを作成する関数`
///
/// ```
/// aaaaa:bbbbb:ccccc:ddddd
/// ```
///
/// t_str_list [
///  aaaaa,
///  bbbbb,
///  ccccc,
///  ddddd
/// ]
t_str_list *str_list_split(char *str, char c)
{
	t_str_list *r;
	char *str_tmp;
	size_t s;
	size_t l;

	str_tmp = str;
	r = NULL;
	s = 0;
	l = 0;
	while (*str != '\0')
	{
		if (*str == c)
		{
			str_list_push(
				&r,
				remove_char_from_split_string(
					str_tmp, s, l, c)
			);
			s += l;
			l = 0;
		}
		l += 1;
		str++;
	}
	str_list_push(&r, remove_char_from_split_string(
				str_tmp, s, l, c));
	return (r);
}
