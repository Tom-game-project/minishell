#ifdef DEBUG
#include <unistd.h>
int debug_getppid()
{
	return (getppid());
}
#else

int debug_getppid()
{
	return (0);
}
#endif
