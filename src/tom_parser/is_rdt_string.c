#include "strtools.h"

bool is_rdt_string(char *str)
{
	return (
		ft_streq(str, "<<") || \
		ft_streq(str, ">>") || \
		ft_streq(str, ">") || \
		ft_streq(str, "<")
	);
}

