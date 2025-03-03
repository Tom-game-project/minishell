#include "list.h"
#include "libft.h"
#include "strtools.h"
#include "parser.h"

#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#ifndef BUF_SIZE
# define BUF_SIZE 1
#endif

/// 改行を含むかどうかをチェックする関数
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

/// 改行がある部分までで切り取る関数
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

/// here docとして
/// ユーザの入力を受け取る関数
int read_heredocline(
	char *eof,
       	int fd
)
{
	t_str_list *lst;
	char buf[BUF_SIZE];
	int index;
	char *str;

	lst = NULL;
	while (1)
	{
		ft_memset(buf, '\0', BUF_SIZE);
		if (read(STDIN_FILENO, buf, BUF_SIZE) == 0)
			break;
		str_list_push(&lst, ft_strdup(buf));
		index = str_list_search_index(lst, includes_newline);
		if (index != -1)
		{
			str = candy_cutter(&lst, index);
			if (ft_streq(str, eof))
				break;
			if (write(fd, str, ft_strlen(str)) == -1)
			{
				str_list_clear(&lst, free);
				free(str);
				return (-1);
			}
			free(str);
		}
	}
	str_list_clear(&lst, free);
	free(str);
	return (0);
}

/// astが含んでいるheredocの数をカウントする関数
int
count_heredoc(t_ast *ast)
{
	int count;

	count = 0;
	if (ast == NULL)
		return (count);
	if (ast->ope == e_ope_heredoc_i)
		count += 1;
	count += count_heredoc(ast->left_ast);
	count += count_heredoc(ast->right_ast);
	return (count);
}

