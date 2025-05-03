#include "libft.h"

int report_cd_home_not_set(void)
{
	ft_putstr_fd("minishell: cd: HOME not set\n", STDERR_FILENO);
	return (1);
}
