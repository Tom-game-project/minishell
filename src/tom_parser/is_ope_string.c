#include <stdbool.h>
#include "strtools.h"

bool is_ope_string(char *str)
{
	return (
		ft_streq(str, "||") || \
		ft_streq(str, "|") || \
		ft_streq(str, "&&")
	);
}
