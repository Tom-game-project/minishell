/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reconnect2stdin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:34:49 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/03 18:34:56 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

/// シグナル発生で切断された標準入力を復元させる
///
void	reconnect_stdin(int *exit_status)
{
	int	tty_fd;

	if (!isatty(STDIN_FILENO))
	{
		*exit_status = 130;
		tty_fd = open("/dev/tty", O_RDONLY);
		if (tty_fd != -1)
		{
			dup2(tty_fd, STDIN_FILENO);
			close(tty_fd);
		}
	}
}
