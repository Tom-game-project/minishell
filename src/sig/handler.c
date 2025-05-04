/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:34:26 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/30 20:37:38 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sig.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <fcntl.h>
#include <unistd.h>

#include "sig.h"

void	handle_sig(int sig)
{
	g_signal_number = sig;
	if (sig == SIGINT)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		disconnect2stdin();
	}
}

void	handle_sig2(int sig)
{
	g_signal_number = sig;
	if (sig == SIGINT)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
	}
}
