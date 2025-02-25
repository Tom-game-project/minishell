#include "list.h"
#include "libft.h"
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

// for test
// #include <stdio.h>


static bool is_num(char *str)
{
	int i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		i += 1;
	}
	while (str[i] == '\0')
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i += 1;
	}
	return (true);
}

int built_in_exit(t_str_list *args)
{
	char *str;

	if (str_list_len(args) == 0)
	{
		// exit直前のリソースの解放はOSの仕事
		// リークではない
		exit(0);
	}
	else
	{
		str = str_list_get_elem(args, 1);
		if (is_num(str))
		{
			//dprintf(STDERR_FILENO, "%d\n", ft_atoi(str) % 256);
			exit(ft_atoi(str) % 256);
		}
		else
		{
			// numeric argument required
			exit(2);
		}
	}
	return (2);
}
