#include "envtools.h"
#include "stdbool.h"

bool is_valid_identifier(char *str)
{
	while (*str != '\0')
	{
		if (!is_valid_env_char(*str))
			return (false);
			
		str++;
	}
	return (true);
}
