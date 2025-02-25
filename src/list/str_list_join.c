#include "libft.h"
#include "list.h"
#include "str_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "str_list.h"


/// 文字列をコピーしていく関数
/// 危険な関数なので外部から呼び出して使用しない
static char *unsafe_copy_string(char **target, char *str)
{
	while (*str != '\0')
	{
		**target = *str;
		str++;
		(*target)++;
	}
	return (*target);
}

/// 要素をsepで区切ったstrを返却する
/// 
/// ```
/// t_str_list *node: List["word1", "word2", "word3"]
/// char *sep       : "(^_^)"
/// -----------------------------------------------
/// return char *:"word1(^_^)word2(^_^)word3"
/// ```
char *str_list_join(t_str_list *node, char *sep)
{
	char *str;
	char *str_tmp;

	str = (char *) malloc(\
		sizeof(char) * (
			str_list_len_sum(node) +\
			(str_list_len(node) - 1) * ft_strlen(sep)\
			+ 1));
	str_tmp = str;
	while (node != NULL)
	{
		if (node->ptr.str == NULL)
		{
		}
		else
		{
			str = unsafe_copy_string(&str, node->ptr.str);
			if (node->next != NULL)
				str = unsafe_copy_string(&str, sep);
		}
		node = node->next;
	}
	*str = '\0';
	return (str_tmp);
}
