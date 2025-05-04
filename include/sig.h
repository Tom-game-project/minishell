/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 21:23:32 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/30 19:48:41 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIG_H
# define SIG_H

extern int	g_signal_number;

void	disable_ctrl_backslash(void);

void	disconnect2stdin(void);
void	reconnect_stdin(int *exit_status);

void	handle_sig(int sig);
void	handle_sig2(int sig);

int		sig_settig(void);

int		set_sigint_default(void);

int		set_sigint_ignore(void);

int		set_sigint_handle_sig(void);

#endif
