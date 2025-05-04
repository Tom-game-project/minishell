#include "list.h"
#include "libft.h"

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

#include <stdio.h>

#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include "sig.h"
#include "heredoc.h"

static int putchar_switcher(char c, int fd)
{
	if (isatty(STDIN_FILENO))
		ft_putchar_fd(c, fd);
	return (0);
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
	if (c == 4)
		return (read_heredocline_helper2_eot(lst));
	else if (c == 127 || c == '\b')
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
		char_list_push(lst, c);
	return (e_continue);
}

void enable_raw_mode(struct termios *orig_termios) {
    struct termios raw;
    tcgetattr(STDIN_FILENO, orig_termios);
    raw = *orig_termios;
    raw.c_lflag &= ~(ECHO | ICANON);
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
	put_switcher(HEREDOC_PROMPT, STDOUT_FILENO);
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
