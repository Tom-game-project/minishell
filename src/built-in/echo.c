#include "list.h"
#include "strtools.h"
#include "libft.h"

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

/// この`echo`関数はbashのそれとは違います
/// -nに重複した引数を許しません
///
/// 良い例
///
/// ```bash
/// echo -n hello world
/// ```
/// 良くない例
/// ```bash
/// echo -nnn hello world
/// ```
int built_in_echo(t_str_list *args)
{
	int exit_status;
	bool newline_flag;

	exit_status = 0;
	newline_flag = true;
	if (str_list_len(args) == 1)
		return (0);
	args = args->next;
	if (ft_streq(str_list_get_elem(args, 0), "-n"))
	{
		newline_flag = false;
		args = args->next;
	}
	while (args != NULL)
	{
		write(STDOUT_FILENO, args->ptr.str, ft_strlen(args->ptr.str));
		if (args->next != NULL)
			write(STDOUT_FILENO, &" ", 1);
		args = args->next;
	}
	if (newline_flag)
		write(STDOUT_FILENO, &"\n", 1);
	return (exit_status);
}
