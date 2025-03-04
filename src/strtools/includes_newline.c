#include <stdbool.h>

bool includes_newline(char *str)
{
	while (*str != '\0')
	{
		if (*str == '\n')
			return (true);
		str++;
	}
	return (false);
}

