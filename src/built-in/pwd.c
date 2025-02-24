#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>

#include "libft.h"


/// 
/// 返り値exit_status
///
int built_in_pwd()
{
	char buf[PATH_MAX];

	if (getcwd(buf, PATH_MAX) == NULL)
	{
		perror("minishell");
		return (1);
	}
	ft_putstr_fd(buf, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	return (0);
}
