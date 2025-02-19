#include "list.h"
#include "libft.h"

#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#ifndef BUF_SIZE
# define BUF_SIZE 1
#endif

static bool includes_newline(char *str)
{
	while (*str != '\0')
	{
		if (*str == '\n')
			return (true);
		str++;
	}
	return (false);
}

static char *
candy_cutter(t_str_list **lst, int index)
{
	t_str_list *t;
	char *str;

	t = str_list_cut(lst, index);
	str = str_list_join(t, "");
	str_list_clear(&t, free);
	return (str);
}

// char *candy_gather(t_str_list **bag, int index)
// {
// 	return ()
// }

/// 文字列
t_str_list *
read_heredocline(char *eof)
{
	t_str_list *lst;
	t_str_list *lst2;
	char buf[BUF_SIZE];
	int index;
	char *str;

	lst = NULL;
	lst2 = NULL;
	while (1)
	{
		ft_memset(buf, '\0', BUF_SIZE);
		if (read(STDIN_FILENO, buf, BUF_SIZE) == 0)
			break;
		str_list_push(&lst, ft_strdup(buf));
		index = str_list_search_index(lst, includes_newline);
		if (index != -1)
		{
			// 見つかったのなら
			str = candy_cutter(&lst, index);
			str_list_push(&lst2, str);
			if (
					ft_strlen(eof) == ft_strlen(str) &&
					ft_strncmp( str, eof, ft_strlen(str)) == 0
			)
				break;
		}
	}
	return (lst2);
}

int main()
{
	t_str_list *a;
	a = read_heredocline("EOF\n");
	str_list_print(a);
	str_list_clear(&a, free);
	return (0);
}
