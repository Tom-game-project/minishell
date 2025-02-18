
# include "parser.h"
# include "libft.h"
# include <limits.h>
# include <stdio.h>

static int	find_chr(char *input, char find);

int find_syntax(char *input)//syntaxエラーの時はマイナス値を返すように設計
{
	int idx;

	if (ft_strncmp(input, "$(", 2) == 0)
		idx = find_chr(input + 2, ')') + 3;
	else if (*input == '(')
		idx = find_chr(input + 1, ')') + 2;
	else
	 	return (0);
	return (idx);
}

static int	find_chr(char *input, char find)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (find == '"' && find == '\'')
	{
		while (input[i] != '\0')
		{
			if (input[i] == '"' || input[i] == '\'')
				count++;
			i++;
		}
		if (count % 2 == 0)
			return (INT_MIN);
	}
	i = 0;
	while (input[i] != '\0')
	{
		if (find != '"' && find != '\'')
			i += find_syntax(input + i);
		if (input[i] == find)
		{
			if (count == 0)
				return (i);
			count--;
		}
		i++;
	}
	return (INT_MIN);
}
