#ifdef DEBUG
#include <unistd.h>
int debug_getpid()
{
	return (getpid());
}
#else

int debug_getpid()
{
	return (0);
}
#endif
