/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disable_ctrl_backslash.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:33:04 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/21 18:33:44 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <unistd.h>

/// # disable_ctrl_backslash
///
/// `ctrl-\`を無効化する関数
void	disable_ctrl_backslash(void)
{
	struct termios	orig_termios;
	struct termios	new_termios;

	tcgetattr(STDIN_FILENO, &orig_termios);
	new_termios = orig_termios;
	new_termios.c_cc[VQUIT] = _POSIX_VDISABLE;
	tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
}


