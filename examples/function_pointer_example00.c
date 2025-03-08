#include <stdio.h>
#include <unistd.h>


//#define DEBUG ""

#ifdef DEBUG
int (*dprintf_wrap)(int fd, const char *restrict format, ...) = dprintf;
#else
int dprintf_wrap(int fd, const char *restrict format, ...)
{
	(void) fd;
	(void) format;
	return (0);
}
#endif

int main()
{
	dprintf_wrap(STDERR_FILENO, "%s\n", "hello world");
	return (0);
}

