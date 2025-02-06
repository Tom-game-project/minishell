#include "list.h"
#include <stdlib.h>
#include "libft.h"

/// 途中で失敗した場合にfreeをする関数
///
static void clear_string_array(char **arr)
{
	while (*arr == NULL)
	{
		free(*arr);
		arr++;
	}
}

/// 固定長の配列を返却します
///
/// list["word0", "word1", "word2", ...]
/// 
/// とあったときに
///
/// array["word0", "word1", "word2", ..., NULL]
///
/// に変換します
/// ```c
/// return ["allocated string", "allocated string", NULL];
/// ```
char **str_list_to_array(t_str_list *node)
{
	char **array_str;
	char **array_str_tmp;

	array_str = (char **)malloc(sizeof(char *) * (str_list_len(node) + 1)); // NULLどめ
	if (array_str == NULL)
		return (NULL);
	array_str_tmp = array_str;
	while (node != NULL)
	{
		*array_str = ft_strdup(node->str);
		if (*array_str == NULL)
		{
			clear_string_array(array_str_tmp);
			free(array_str_tmp);
			return (NULL);
		}
		node = node->next;
		array_str++;
	}
	*array_str = NULL;
	return (array_str_tmp);
}
