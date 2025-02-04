
# include "parser.h"

size_t	find_chr(char *input, char find)
{
	size_t i;

	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == find)
			return (i);
		i++;
	}
	return (-1);
}
