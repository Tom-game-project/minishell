/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@syudent.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 04:12:42 by kaara             #+#    #+#             */
/*   Updated: 2024/06/06 20:49:38 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = strlen(s);
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (i < len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	return (result);
}

// char toggle_case(unsigned int n, char c) {
//     (void)n;
//     if (c >= 'a' && c <= 'z')
//         return c - 32;
//     else if (c >= 'A' && c <= 'Z')
//         return c + 32;
//     return c;
// }

// int main() {
//     char const *str = "Hello, World!";
//     char *modified_str = ft_strmapi(str, toggle_case);
//     if (modified_str) {
//         printf("Original: %s\n", str);
//         printf("Modified: %s\n", modified_str);
//         free(modified_str);
//     }
//     return 0;
// }