#include "asterisk.h"
#include "parser.h"
#include <stdbool.h>

bool	is_asterisk(char *input)
{
	int idx;

	idx = 0;
	while (*(input + idx) != '\0')
	{
		if (*(input + idx) == '*')
			return (true);
		update_idx(input + idx, idx);
	}
	return (false);
}
