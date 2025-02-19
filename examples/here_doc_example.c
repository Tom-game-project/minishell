#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#ifndef BUF_SIZE
# define BUF_SIZE 1024
#endif

int main()
{
	char buf[BUF_SIZE];
	char eof[] = "EOF\n";

	while (1)
	{
		memset(buf, '\0', BUF_SIZE);
		if (read(STDIN_FILENO, buf, BUF_SIZE) == 0)
			break;
		if (
				strlen(eof) == strlen(buf) &&
				strncmp( eof, buf, strlen(eof)) == 0)
			break;
		write(STDOUT_FILENO, buf, BUF_SIZE);
	}
	return (0);
}
