#include "list.h"
#include "libft.h"
#include "strtools.h"

#include <unistd.h>
#include <fcntl.h>

#include <termios.h>
#include <unistd.h>
#include "heredoc.h"

int put_switcher(char *str, int fd)
{
	if (isatty(STDIN_FILENO))
		ft_putstr_fd(str, fd);
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

