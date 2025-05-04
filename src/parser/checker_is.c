/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_is.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:30:22 by kaara             #+#    #+#             */
/*   Updated: 2025/05/03 15:30:22 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include <stdbool.h>

bool	is_enclosed_by_parentheses(char *element);
bool	is_enclosed_by_single_quotes(char *element);
bool	is_enclosed_by_double_quotes(char *element);

bool	is_string(char *element)
{
	if (is_enclosed_by_parentheses(element))
		return (true);
	if (is_enclosed_by_single_quotes(element))
		return (true);
	if (is_enclosed_by_double_quotes(element))
		return (true);
	return (false);
}

bool	is_enclosed_by_parentheses(char *element)
{
	int	i;

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
	}
	return (false);
}

bool	is_enclosed_by_single_quotes(char *element)
{
	int	i;

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
	}
	return (false);
}

bool	is_enclosed_by_double_quotes(char *element)
{
	int	i;

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
	}
	return (false);
}
