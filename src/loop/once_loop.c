#include <readline/readline.h>
#include <readline/history.h>
#include "loop_private.h"
#include "libft.h"

static char	*none_device_readline()
{
	char		c;
	t_char_list	*lst;
	char		*str;

	lst = NULL;
	while (1)
	{
		c = '\0';
		if (read(STDIN_FILENO, &c, 1) == 0)
			break ;
		char_list_push(&lst, c);
		if (c == '\0' || c == '\n')
			break ;
	}
	str = char_list_to_str(lst);
	char_list_clear(&lst);
	return (str);
}

t_loop_cntl	device_once_loop(int *exit_status, bool *newline_flag, t_str_dict **env_dict)
{
	char *input;
	char *prompt_str;
	t_loop_cntl	lctl;

	prompt_str = prompt(*exit_status);
	input = readline(prompt_str);
	free(prompt_str);
	lctl = loop_unit(input, exit_status, env_dict, newline_flag);
	free(input);
	return (lctl);
}

t_loop_cntl
none_device_once_loop(int *exit_status, bool *newline_flag, t_str_dict **env_dict)
{
	char *input;
	t_loop_cntl	lctl;

	input = none_device_readline();
	if (ft_strlen(input) == 0)
		return (e_break);
	lctl = loop_unit(input, exit_status, env_dict, newline_flag);
	free(input);
	return (lctl);
}
