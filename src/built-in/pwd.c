#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#include "libft.h"


int build_in_pwd()
{
	char buf[PATH_MAX];

	if (getcwd(buf, PATH_MAX) == NULL)
	{
		perror("minishell");
		return (1);
	}
	ft_putstr_fd(buf, STDOUT_FILENO);
	return (0);
}
