
#include "libft.h"

int report_cd_too_many_arguments(void)
{
	ft_putstr_fd("minishell: cd: too many arguments\n", STDERR_FILENO);
	return (1);
}
