#include "list.h"
#include "libft.h"
#include "strtools.h"
#include "parser.h"

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

#include <stdio.h>

#include "sig.h"


#ifndef BUF_SIZE
# define BUF_SIZE 1
#endif

#define HEREDOC_PROMPT "> "

typedef enum e_private t_private;
enum e_private
{
	e_continue,
	e_break,
	e_return_error
};


t_private read_heredocline_helper(
	char *eof,
       	int fd,
	t_str_list **lst
)
{
	char buf[BUF_SIZE];
	int index;

	ft_memset(buf, '\0', BUF_SIZE);
	if (read(STDIN_FILENO, buf, BUF_SIZE) == 0)
	{
		//dprintf(STDERR_FILENO,"len %d\n", str_list_len(*lst));

		if (str_list_len(*lst) == 0 || g_signal_number == SIGINT)
		{
			return (e_break);
		}
	}
	str_list_push(lst, ft_strdup(buf));
	index = str_list_search_index(*lst, includes_newline);
	if (index != -1)
	{
		char *str;
		str = NULL;
		str = candy_cutter(lst, index);
		if (ft_streq(str, eof))
			return (e_break);
		ft_putstr_fd(HEREDOC_PROMPT, STDERR_FILENO);// TODO stdinがデバイス出ない場合は、入らないようにする
		if (write(fd, str, ft_strlen(str)) == -1)
		{
			str_list_clear(lst, free);
			free(str);
			return (e_break);
		}
		free(str);
	}
	return (e_continue);
}


/// here docのインターフェイス
/// ユーザの入力を受け取る関数
int read_heredocline(
	char *eof,
       	int fd
)
{
	t_str_list *lst;
	t_private p;

	lst = NULL;
	ft_putstr_fd(HEREDOC_PROMPT, STDERR_FILENO); // TODO stdinがデバイス出ない場合は、入らないようにする
	while (1)
	{
		p = read_heredocline_helper(eof, fd, &lst);
		if (p == e_break || p == e_return_error)
			break ;
	}
	str_list_clear(&lst, free);
	if (g_signal_number == SIGINT)
		return (130);
	return (0);
}

/// astが含んでいるheredocの数をカウントする関数
int count_heredoc(t_ast *ast)
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

