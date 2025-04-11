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
#include "test_tools.h"

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

int 
put_switcher(char *str, int fd)
{
	if (isatty(STDIN_FILENO))
		ft_putstr_fd(str, fd);
	return (0);
}

int 
putchar_switcher(char c, int fd)
{
	if (isatty(STDIN_FILENO))
		ft_putchar_fd(c, fd);
	return (0);
}

t_private read_heredocline_helper2_eot(
	t_char_list **lst
)
{
	if (char_list_len(*lst) == 0)
	{
		put_switcher("\n", STDOUT_FILENO);
		return (e_break);
	}
	else
		return (e_continue);
}

t_private read_heredocline_helper2_baskspace(
	t_char_list **lst
)
{
	if (0 < char_list_len(*lst))
	{
		char_list_pop(lst, char_list_len(*lst) - 1);
		put_switcher("\b \b", STDOUT_FILENO);
	}
	return (e_continue);
}


t_private read_heredocline_helper2_newline(
	char *eof,
       	int fd,
	t_char_list **lst
){
	char *str;

	char_list_push(lst, '\n');
	str = char_list_to_str(*lst);
	if (ft_streq(eof, str))
	{
		free(str);
		put_switcher("\n", STDOUT_FILENO);
		return (e_break);
	}
	if (write(fd, str, ft_strlen(str)) == -1)
	{
		free(str);
		return (e_break);
	}
	free(str);
	put_switcher("\n", STDOUT_FILENO);
	put_switcher(HEREDOC_PROMPT, STDERR_FILENO);
	char_list_clear(lst);
	return (e_continue);
}

t_private read_heredocline_helper2(
	char *eof,
       	int fd,
	t_char_list **lst
)
{
	unsigned char c;

	if (read(STDIN_FILENO, &c, BUF_SIZE) <= 0)
		return (e_break);

	debug_dprintf(STDERR_FILENO, "binary %x\n", c);
	if (c == 4) // EOT
		return (read_heredocline_helper2_eot(lst));
	else if (c == 127 || c == '\b') // Back Space 及びDelの処理
		return (read_heredocline_helper2_baskspace(lst));
	else if (c == '\n')
		return (read_heredocline_helper2_newline(eof, fd, lst));
	else if (ft_isprint(c))
	{
		char_list_push(lst, c);
		putchar_switcher(c, STDOUT_FILENO);
		return (e_continue);
	}
	else 
	{
		char_list_push(lst, c);
	}
	return (e_continue);
}

//// 修正バージョン
void enable_raw_mode(struct termios *orig_termios) {
    struct termios raw;
    tcgetattr(STDIN_FILENO, orig_termios);
    raw = *orig_termios;
    raw.c_lflag &= ~(ECHO | ICANON); // カノニカルモードを無効化
				     // ICANON | ECHO | ECHOE | ISIG
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
	put_switcher(HEREDOC_PROMPT, STDOUT_FILENO); // TODO stdinがデバイス出ない場合は、入らないようにする
	while (1)
	{
		p = read_heredocline_helper2(eof, fd, &lst);
		if (g_signal_number == SIGINT)
		{
			ft_putstr_fd("^C", STDOUT_FILENO);
			exit_status = 130;
			reconnect_stdin(&exit_status);
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

