#include "libft.h"
#include <stdbool.h>

#define BUF_SIZE 1024

/// fdに書き込まれた内容を標準出力に書き込む
int fd_write(int fd)
{
	char buf[BUF_SIZE];

	ft_memset(buf, '\0', BUF_SIZE);
	while(1)
	{
		if (read(fd, buf, BUF_SIZE) == 0)
			break ;
		write(STDOUT_FILENO, buf, BUF_SIZE);
	}
	return (0);
}
