#include "libft.h"
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

// EOFを知るために、ここのマクロのサイズは1で固定的でなければならない
#define READ_BUF_SIZE 1

/// fdに書き込まれた内容を標準出力に書き込む
///
/// バイナリが送られる可能性もある
int fd_write(int from_fd, int to_fd)
{
	char buf[READ_BUF_SIZE];

	while(1)
	{
		ft_memset(buf, '\0', READ_BUF_SIZE);
		if (read(from_fd, buf, READ_BUF_SIZE) == 0)
			break ;
		write(to_fd, buf,READ_BUF_SIZE);
		// dprintf(STDERR_FILENO, "[%c]\n", *buf);
	}
	return (0);
}
