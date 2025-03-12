#include <stdio.h>
#include <stdarg.h>
#include <stdarg.h>

// __attribute__((format(printf, 1, 2))) の意味:
// - 第一引数 (1) はフォーマット文字列 (`const char *format`)
// - 第二引数 (2) は可変長引数 (`...`)

#ifdef DEBUG

int debug_dprintf(int fd, const char *format, ...)
{
	va_list args;
	int rv;

	va_start(args, format);
	rv = vdprintf(fd, format, args);
	va_end(args);
	return (rv);
}
#else

int debug_dprintf(int fd,const char *format, ...)
{
	(void) fd;
	(void) format;
	return (0);
}
#endif


