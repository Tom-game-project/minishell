#include "libft.h"
#include <stdbool.h>

bool ft_streq(char *a, char *b)
{
	if (ft_strlen(a) == ft_strlen(b))
	{
		while (*a != '\0')
		{
			if (*a != *b)
				return (false);
			a++;
			b++;
		}
		return (true);
	}
	else
		return (false);
}

