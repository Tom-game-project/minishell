/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@syudent.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 01:47:00 by kaara             #+#    #+#             */
/*   Updated: 2024/05/31 23:35:05 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_delimiter(char s, char c)
{
	return (s == c);
}

int	count_elements(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && is_delimiter(*s, c))
			s++;
		if (*s && !is_delimiter(*s, c))
		{
			count++;
			while (*s && !is_delimiter(*s, c))
				s++;
		}
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	int			i;
	int			element_count;
	char		**result;
	const char	*element_start;

	element_count = count_elements(s, c);
	result = (char **)malloc(sizeof(char *) * (element_count + 1));
	if (!result)
		return (NULL);
	element_count = 0;
	while (*s)
	{
		while (*s && is_delimiter(*s, c))
			s++;
		if (*s && !is_delimiter(*s, c))
		{
			element_start = s;
			while (*s && !is_delimiter(*s, c))
				s++;
			result[element_count] = (char *)malloc(s - element_start + 1);
			if (!result[element_count])
			{
				i = 0;
				while (i < element_count)
					free (result[i++]);
				free (result);
				return (NULL);
			}
			ft_strlcpy(result[element_count], element_start, s - element_start + 1);
			element_count++;
		}
	}
	result[element_count] = NULL;
	return (result);
}

// int main() {
//     char **result = ft_split("hello world this is C", ' ');
//     if (result) {
//         for (int i = 0; result[i] != NULL; i++) {
//             printf("Result[%d]: %s\n", i, result[i]);
//             free(result[i]); // 各文字列のメモリを解放
//         }
//         free(result); // 文字列配列のメモリを解放
//     }
//     return 0;
// }