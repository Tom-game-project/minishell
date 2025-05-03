/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_unit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:27:19 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/03 18:27:19 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "envtools.h"
#include "libft.h"
#include "loop_private.h"
#include "sig.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>

static t_loop_cntl	device_loop_unit_head_setting(char *input, int *exit_status,
		bool *newline_flag)
{
	if (g_signal_number == SIGINT)
	{
		if (*exit_status != 130 || *newline_flag)
		{
			write(STDOUT_FILENO, &"\n", 1);
			*newline_flag = false;
		}
		reconnect_stdin(exit_status);
		g_signal_number = 0;
		return (e_continue);
	}
	else if (input == NULL)
	{
		ft_putstr_fd("exit\n", STDERR_FILENO);
		return (e_break);
	}
	else
		return (e_through);
}

/// 一回のloop
t_loop_cntl	loop_unit(char *input, int *exit_status, t_str_dict **env_dict,
		bool *newline_flag)
{
	int			flag;
	t_loop_cntl	cntl;

	cntl = device_loop_unit_head_setting(input, exit_status, newline_flag);
	if (cntl != e_through)
		return (cntl);
	add_history(input);
	flag = exec_shell_cmd(input, env_dict, exit_status);
	set_sigint_handle_sig();
	update_exit_status(*exit_status, env_dict);
	if (g_signal_number == SIGINT || *exit_status == 130)
	{
		if (flag)
			write(STDOUT_FILENO, &"\n", 1);
		*newline_flag = true;
		reconnect_stdin(exit_status);
		g_signal_number = 0;
	}
	return (e_continue);
}
