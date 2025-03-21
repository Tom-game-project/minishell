#include <stdbool.h>

bool is_ifs(char c)
{
	return (
		c == '\t' || \
		c == '\n' || \
		c == ' '
	);
}

