/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_setting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:35:26 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/30 20:37:51 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sig.h"
#include "signal.h"
#include <stdlib.h>

/// イベントハンドラの設定
int	sig_settig(void)
{
	struct sigaction	sa_sigact;

	sa_sigact.sa_handler = handle_sig;
	sigemptyset(&sa_sigact.sa_mask);
	sa_sigact.sa_flags = 0;
	sigaction(SIGQUIT, &sa_sigact, NULL);
	sigaction(SIGINT, &sa_sigact, NULL);
	disable_ctrl_backslash();
	return (0);
}

int	set_sigint_default(void)
{
	struct sigaction	sa_sigact;

	sa_sigact.sa_handler = SIG_DFL;
	sigemptyset(&sa_sigact.sa_mask);
	sa_sigact.sa_flags = 0;
	sigaction(SIGINT, &sa_sigact, NULL);
	return (0);
}

int	set_sigint_ignore(void)
{
	struct sigaction	sa_sigact;

	sa_sigact.sa_handler = SIG_IGN;
	sigemptyset(&sa_sigact.sa_mask);
	sa_sigact.sa_flags = 0;
	sigaction(SIGINT, &sa_sigact, NULL);
	return (0);
}

int	set_sigint_handle_sig(void)
{
	struct sigaction	sa_sigact;

	sa_sigact.sa_handler = handle_sig;
	sigemptyset(&sa_sigact.sa_mask);
	sa_sigact.sa_flags = 0;
	sigaction(SIGINT, &sa_sigact, NULL);
	return (0);
}
