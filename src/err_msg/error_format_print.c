#include "libft.h"
#include "list.h"
#include <unistd.h>

static void nop(void *ptr)
{
	(void) ptr;
}

void print_error_format_string(char *cmd, char *msg)
{
	t_str_list *lst;
	char *str;

	lst = NULL;
	str_list_push(&lst, "minishell:");
	str_list_push(&lst, cmd);
	str_list_push(&lst, msg);
	str = str_list_join(lst, " ");
	str_list_clear(&lst, nop);
	ft_putstr_fd(str , STDERR_FILENO);
	free(str);
}
