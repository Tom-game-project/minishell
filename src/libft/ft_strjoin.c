/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 05:50:39 by kaara             #+#    #+#             */
/*   Updated: 2024/06/25 20:01:56 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*mix_str;
	size_t	prefix_len;
	size_t	mix_len;

	prefix_len = ft_strlen(s1);
	mix_len = prefix_len + ft_strlen(s2);
	mix_str = (char *)malloc(mix_len + 1);
	if (!mix_str)
		return (NULL);
	ft_memcpy (mix_str, s1, prefix_len);
	ft_memcpy (mix_str + prefix_len, s2, mix_len - prefix_len);
	mix_str[mix_len] = '\0';
	return (mix_str);
}
