/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 01:47:00 by kaara             #+#    #+#             */
/*   Updated: 2024/06/25 20:01:23 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_elements(const char *s, char c);
static char	*cpy_result(const char *s, char c);
static void	free_result(char **result, int element_count);

char	**ft_split(const char *s, char c)
{
	int			element_count;
	char		**result;

	element_count = count_elements(s, c);
	result = (char **)malloc(sizeof(char *) * (element_count + 1));
	if (!result)
		return (NULL);
	element_count = 0;
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s && !(*s == c))
		{
			result[element_count] = cpy_result(s, c);
			if (!result[element_count])
				return (free_result(result, element_count), NULL);
			while (*s && !(*s == c))
				s++;
			element_count++;
		}
	}
	result[element_count] = NULL;
	return (result);
}

static int	count_elements(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s && !(*s == c))
		{
			count++;
			while (*s && !(*s == c))
				s++;
		}
	}
	return (count);
}

static char	*cpy_result(const char *s, char c)
{
	char		*cpy_element;
	const char	*element_start;

	element_start = s;
	while (*s && !(*s == c))
		s++;
	cpy_element = (char *)malloc(s - element_start + 1);
	if (!cpy_element)
		return (NULL);
	ft_strlcpy(cpy_element, element_start, s - element_start + 1);
	return (cpy_element);
}

static void	free_result(char **result, int element_count)
{
	int	i;

	i = 0;
	while (i < element_count)
		free(result[i++]);
	free(result);
}
