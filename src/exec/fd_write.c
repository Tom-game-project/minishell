/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:15:17 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/12 20:15:55 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

// EOFを知るために、ここのマクロのサイズは1で固定的でなければならない
#define READ_BUF_SIZE 1

/// fdに書き込まれた内容を標準出力に書き込む
///
/// バイナリが送られる可能性もある
int	fd_write(int from_fd, int to_fd)
{
	char	buf[READ_BUF_SIZE];

	while (1)
	{
		ft_memset(buf, '\0', READ_BUF_SIZE);
		if (read(from_fd, buf, READ_BUF_SIZE) == 0)
			break ;
		write(to_fd, buf, READ_BUF_SIZE);
	}
	return (0);
}
