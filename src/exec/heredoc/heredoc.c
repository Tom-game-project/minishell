#include "list.h"
#include "libft.h"
#include "strtools.h"
#include "parser.h"

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

#include <stdio.h>

#include <stdio.h>
#include <termios.h>
#include <unistd.h>
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
	//dprintf(STDERR_FILENO, "\n");
	//str_list_print(*lst);
	if (read(STDIN_FILENO, buf, BUF_SIZE) == 0)
	{
		//dprintf(STDERR_FILENO,"len %d\n", str_list_len(*lst));
		//dprintf(STDERR_FILENO, "EOF 送出 %d", g_signal_number);

		if (str_list_len(*lst) == 0 || g_signal_number == SIGINT)
		{
			return (e_break);
		}
		else if (g_signal_number == 0)
		{
			int exit_status;
			exit_status = 1;
			reconnect_stdin(&exit_status);
			return (e_continue);
		}
	}
	if (ft_strlen(buf) != 0)
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



t_private read_heredocline_helper2(
	char *eof,
       	int fd,
	t_char_list **lst
)
{
	char c;

	if (read(STDIN_FILENO, &c, BUF_SIZE) <= 0)
		return (e_break);
	if (c == 4) // EOT
		if (char_list_len(*lst) == 0)
			return (e_break);
		else
			return (e_continue);
	else if (c == 127 || c == '\b') // Back Space 及びDelの処理
	{
		if (0 < char_list_len(*lst)){
			char_list_pop(lst, char_list_len(*lst) - 1);
			ft_putstr_fd("\b \b", STDOUT_FILENO);
		}
		return (e_continue);
	}
	else if (c == '\n')
	{
		char *str;

		char_list_push(lst, c);
		str = char_list_to_str(*lst);
		if (ft_streq(eof, str))
		{
			free(str);
			return (e_break);
		}
		if (write(fd, str, ft_strlen(str)) == -1)
		{
			free(str);
			return (e_break);
		}
		free(str);
		ft_putchar_fd(c, STDOUT_FILENO);
		ft_putstr_fd(HEREDOC_PROMPT, STDERR_FILENO);
		char_list_clear(lst);
		return (e_continue);
	}
	else if (ft_isprint(c))
	{
		char_list_push(lst, c);
		ft_putchar_fd(c, STDOUT_FILENO);
		return (e_continue);
	}
	return (e_continue);
}

//// 修正バージョン
void enable_raw_mode(struct termios *orig_termios) {
    struct termios raw;
    tcgetattr(STDIN_FILENO, orig_termios);
    raw = *orig_termios;
    raw.c_lflag &= ~(ECHO | ICANON); // カノニカルモードを無効化
    tcsetattr(STDIN_FILENO, TCSANOW, &raw);
}

void disable_raw_mode(struct termios *orig_termios) {
    tcsetattr(STDIN_FILENO, TCSANOW, orig_termios);
}

int read_heredocline2(
	char *eof,
       	int fd
)
{
	struct termios orig_termios;
	t_char_list *lst;
	t_private p;
	int exit_status;

	enable_raw_mode(&orig_termios);
	lst = NULL;
	exit_status = 0;
	ft_putstr_fd(HEREDOC_PROMPT, STDERR_FILENO); // TODO stdinがデバイス出ない場合は、入らないようにする
	while (1)
	{
		p = read_heredocline_helper2(eof, fd, &lst);
		if (g_signal_number == SIGINT)
		{
			ft_putstr_fd("^C", STDOUT_FILENO);
			exit_status = 130;
			break ;
		}
		if (p == e_break || p == e_return_error)
			break ;
	}
	char_list_clear(&lst);
	disable_raw_mode(&orig_termios);
	return (exit_status);
}

/// here docのインターフェイス
/// ユーザの入力を受け取る関数

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

