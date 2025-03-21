#include <stdbool.h>

bool is_ope_char(char c)
{
	return (
		c == '<' || \
		c == '>' || \
		c == '|' || \
		c == '&'
	);
}

