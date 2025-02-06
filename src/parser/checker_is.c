#include "parser.h"
#include "libft.h"
#include <stdbool.h>
#include <stdio.h>

bool	is_enclosed_by_parentheses(char *element);
bool	is_enclosed_by_single_quotes(char *element);
bool	is_enclosed_by_double_quotes(char *element);

bool is_string(char *element)//searchで’””みたいなケース正常に処理できるか不安
{
	if (is_enclosed_by_parentheses(element))
		return (true);
	if (is_enclosed_by_single_quotes(element))
		return (true);
	if (is_enclosed_by_double_quotes(element))
		return (true);
	return (false);
}

bool is_enclosed_by_parentheses(char *element)
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
	return (false);
}

bool is_enclosed_by_single_quotes(char *element)
{
	int i;

	i = 0;
	if (element[i] == '"')
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
	return (false);
}

bool is_enclosed_by_double_quotes(char *element)
{
	int i;

	i = 0;	
	if (element[i] == '(')
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

bool ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}