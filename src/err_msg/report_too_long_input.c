
#include "libft.h"

int report_too_long_input(void)
{
	ft_putstr_fd("minishell : too long input\n", STDERR_FILENO);
	return (1);
}
