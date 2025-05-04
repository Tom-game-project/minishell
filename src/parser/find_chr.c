/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_chr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:48:41 by kaara             #+#    #+#             */
/*   Updated: 2025/05/03 15:48:41 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include <limits.h>
#include <unistd.h>

static int	case_dquotes(char *input, char find);
static int	case_quote(char *input, char find);
static int	find_chr(char *input, char find);

int	find_syntax(char *input)//syntaxエラーの時はマイナス値を返すように設計
{
	int	idx;

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
	int	i;
	int	tmp;
	int	count;

	i = 0;
	count = case_dquotes(input, find);
	count += case_quote(input, find);
	while (input[i] != '\0')
	{
		if (find != '"' && find != '\'')
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

static int	case_dquotes(char *input, char find)
{
	int	i;
	int	count;

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
	return (count);
}

static int	case_quote(char *input, char find)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
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
	return (count);
}
