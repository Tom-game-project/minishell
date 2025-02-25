#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "string.h"


#define SHADOW_FILE_NAME "./.minishell"


#define BUFFER_SIZE 1024

int main()
{
	int fd;
	int new_fd;
	char buf[BUFFER_SIZE];
	size_t n;

	fd = open(SHADOW_FILE_NAME, O_RDWR | O_CREAT, 0644);
	if (fd == -1)
	{
		printf("could not opne the file\n");
		return (1);
	}

	if (unlink(SHADOW_FILE_NAME) < 0)
	{
		close(fd);
		return (1);
	}

	write(fd, "helloworld", 10);
	new_fd = dup(fd);
	memset(buf, '\0', BUFFER_SIZE); // bufの初期化
	n = read(new_fd, &buf[0], BUFFER_SIZE - 1);
	buf[n] = '\0';
	printf("file contents:%lu: %s\n", n, &buf[0]);

	close(new_fd);
	close(fd);
	return (0);
}
