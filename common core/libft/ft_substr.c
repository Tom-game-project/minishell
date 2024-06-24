/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 02:45:25 by kaara             #+#    #+#             */
/*   Updated: 2024/06/24 21:14:52 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ministr;
	size_t	actual_len;

	actual_len = ft_strlen(s);
	if (actual_len <= start)
	{
		ministr = (char *)malloc(1);
		if (ministr)
			ministr[0] = '\0';
		else
			return (NULL);
		return (ministr);
	}
	if (actual_len - start < len)
		len = actual_len - start;
	ministr = (char *)malloc(len + 1);
	if (!ministr)
		return (NULL);
	ft_strlcpy (ministr, s + start, len + 1);
	return (ministr);
}

// int main(void)
// {
//     char str[11] = "helloworld";
//     unsigned int start = 3;
//     size_t len = 30;
//     char *result = ft_substr(str, start, len);

//     if (result) {
//         printf("%s\n", result);
//         free(result);
//     } else {
//         printf("Failed to allocate memory.\n");
//     }
//     return 0;
// }