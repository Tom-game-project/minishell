
# include "parser.h"
# include "libft.h"
# include <limits.h>
#include <unistd.h>
#include <stdio.h>

static int	find_chr(char *input, char find);

int find_syntax(char *input)//syntaxエラーの時はマイナス値を返すように設計
{
	int idx;

	if (ft_strncmp(input, "$(", 2) == 0)
		idx = find_chr(input + 2, ')') + 2;
	else if (*input == '(')
		idx = find_chr(input + 1, ')') + 1;
	else if (*input == '"')
		idx = find_chr(input + 1, '"') + 1;
	else if (*input == '\'')
		idx = find_chr(input + 1, '\'') + 1;
	else
	 	return (0);
	return (idx);
}

static int	find_chr(char *input, char find)
{
	int i;
	int tmp;
	int count;

	i = 0;
	count = 0;
	if (find == '"')
	{
		while (input[i] != '\0')
		{
			if (input[i] == '"')
				count++;
			i++;
		}
		if (count % 2 == 0)
			return (INT_MIN);
	}
	if (find == '\'')
	{
		while (input[i] != '\0')
		{
			if (input[i] == '\'')
				count++;
			i++;
		}
		if (count % 2 == 0)
			return (INT_MIN);
	}
	i = 0;
	while (input[i] != '\0')
	{
		if (find != '"' && find != '\'')//これきれいにしたい
		{
			tmp = find_syntax(input + i);
			if (tmp < 0)
				break ;
		}
		if (input[i] == find)
		{
			if (find == '"' || find == '\'')
				count--;
			if (count == 0)
				return (i + 1);
		}
		i++;
	}
	return (INT_MIN);
}
