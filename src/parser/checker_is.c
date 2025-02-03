#include "parser.h"
#include "libft.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool is_string(char *element)//searchで’””みたいなケース正常に処理できるか不安
{
	int i;

	i = 0;
	if (element[i] == '\'')
	{
		while (element[i] != '\0')
		{
			if (element[i] == '\'')
				return (true);
		}
		perror("-bash: syntax error near unexpected token `()'");//error文変更の可能性あり
		exit (2);
	}
	else if (element[i] == '"')
	{
		while (element[i] != '\0')
		{
			if (element[i] == '"')
				return (true);
		}
		perror("-bash: syntax error near unexpected token `()'");
		exit (2);
	}
	return (false);
}

bool is_control_operators(char *element)
{
	if (ft_strncmp(element, "&&", 2) == 0)
		return (true);
	if (ft_strncmp(element, "||", 2) == 0)
		return (true);
	if (ft_strncmp(element, "(", 1) == 0)
		return (true);
	if (ft_strncmp(element, ")", 1) == 0)
	{
		perror("-bash: syntax error near unexpected token `('");
		exit (2);
	}
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
