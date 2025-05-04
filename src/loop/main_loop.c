/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:23:17 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/21 18:27:39 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "libft.h"
#include "sig.h"
#include <limits.h>
#include <linux/limits.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <stdbool.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

// private functions
#include "loop_private.h"

int	g_signal_number = 0;

int	main_loop(char *envp[])
{
	t_str_dict	*env_dict;
	int			exit_status;
	t_loop_cntl	lctl;
	bool		newline_flag;

	sig_settig();
	env_dict = NULL;
	envp_to_str_dict(&env_dict, envp);
	exit_status = 0;
	str_dict_add(&env_dict, ft_strdup("?"), ft_itoa(exit_status), free);
	newline_flag = false;
	while (1)
	{
		lctl = device_once_loop(&exit_status, &newline_flag, &env_dict);
		if (lctl == e_break)
			break ;
		else if (lctl == e_continue)
			continue ;
	}
	str_dict_clear(&env_dict, free, free);
	return (exit_status);
}

int	none_device_main_loop(char *envp[])
{
	t_str_dict	*env_dict;
	int			exit_status;
	bool		newline_flag;

	sig_settig();
	env_dict = NULL;
	envp_to_str_dict(&env_dict, envp);
	exit_status = 0;
	str_dict_add(&env_dict, ft_strdup("?"), ft_itoa(exit_status), free);
	newline_flag = false;
	while (1)
	{
		if (none_device_once_loop(&exit_status, &newline_flag,
				&env_dict) == e_break)
			break ;
		else
			continue ;
	}
	str_dict_clear(&env_dict, free, free);
	return (exit_status);
}
