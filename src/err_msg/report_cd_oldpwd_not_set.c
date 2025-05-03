#include "libft.h"

int report_cd_oldpwd_not_set(void)
{
	ft_putstr_fd("minishell: cd: OLDPWD not set\n", STDERR_FILENO);
	return (1);
}
