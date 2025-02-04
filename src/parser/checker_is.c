#include "parser.h"
#include "libft.h"
#include <stdbool.h>
#include <stdio.h>

bool is_string(char *element)//searchで’””みたいなケース正常に処理できるか不安
{
	int i;

	i = 0;
	if (element[i] == '\'')
	{
		i++;
		while (element[i] != '\0')
		{
			if (element[i] == '\'')
				return (true);
			i++;
		}
		perror("-bash: syntax error near unexpected token `()'");//error文変更の可能性あり
	}
	else if (element[i] == '"')
	{
		i++;
		while (element[i] != '\0')
		{
			if (element[i] == '"')
				return (true);
			i++;
		}
		perror("-bash: syntax error near unexpected token `()'");
	}
	else if (element[i] == '(')
	{
		i++;
		while (element[i] != '\0')
		{
			if (element[i] == ')')
				return (true);
			i++;
		}
		perror("-bash: syntax error near unexpected token `()'");
	}
	return (false);
}

bool is_control_operators(char *element)
{
	if (ft_strncmp(element, "&&", 2) == 0)
		return (true);
	if (ft_strncmp(element, "||", 2) == 0)
		return (true);
	return (false);
}

bool is_redirect_operators(char *element)
{
	if (ft_strncmp(element, "<<", 2) == 0)
		return (true);
	if (ft_strncmp(element, ">>", 2) == 0)
		return (true);
	if (ft_strncmp(element, "<", 1) == 0)
		return (true);
	if (ft_strncmp(element, ">", 1) == 0)
		return (true);
	if (ft_strncmp(element, "|", 1) == 0)
		return (true);
	return (false);
}
