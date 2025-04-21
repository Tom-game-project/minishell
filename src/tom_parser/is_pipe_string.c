
#include <stdbool.h>
#include "strtools.h"

bool	is_pipe_string(char *str)
{
	return (
		ft_streq(str, "|")
	);
}
