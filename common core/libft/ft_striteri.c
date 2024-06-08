/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@syudent.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 05:29:09 by kaara             #+#    #+#             */
/*   Updated: 2024/05/31 21:42:26 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// char toggle_case(unsigned int n, char *c) {  // 引数をポインタに変更
//     (void)n;  // 未使用変数の警告を抑制
//     if (*c >= 'a' && *c <= 'z')
//         return *c - 32;  // ポインタの指す値から 'a'-'z' を 'A'-'Z' に変換
//     else if (*c >= 'A' && *c <= 'Z')
//         return *c + 32;  // ポインタの指す値から 'A'-'Z' を 'a'-'z' に変換
//     return *c;
// }

// int main() {
//     char str[] = "hello world";
//     printf("Original string: %s\n", str);
//     ft_striteri(str, toggle_case);
//     printf("Modified string: %s\n", str);
//     return 0;
// }
