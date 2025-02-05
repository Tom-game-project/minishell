
# include "parser.h"

int	find_chr(char *input, char find)
{
	int i;

	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == find)
			return (i);
		i++;
	}
	return (-1);
}
