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
#include "list.h"
#include "libft.h"
#include "envtools.h"
#include "sig.h"

#include <linux/limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <limits.h>
#include <unistd.h>
#include <termios.h>
// シグナル
#include <signal.h>
#include <fcntl.h>

// private functions
#include "loop_private.h"

int g_signal_number = 0;

/// exit statusと、今いるディレクトリを表示するプロンプト
typedef enum e_loop_cntl	t_loop_cntl;
enum e_loop_cntl
{
	e_continue,
	e_break,
};

/// 一回のloop
t_loop_cntl	device_loop_unit(\
	char *input, int *exit_status, t_str_dict **env_dict, bool *newline_flag)
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
		return (e_break);
	add_history(input);
	exec_shell_cmd(input, env_dict, exit_status);
	set_sigint_handle_sig();
	update_exit_status(*exit_status, env_dict);
	if (g_signal_number == SIGINT || *exit_status == 130)
	{
		write(STDOUT_FILENO, &"\n", 1);
		*newline_flag = true;
		reconnect_stdin(exit_status);
		g_signal_number = 0;
	}
	return (e_continue);
}

int	main_loop(char *envp[])
{
	t_str_dict	*env_dict;
	int			exit_status;
	t_loop_cntl	lctl;

	sig_settig();
	env_dict = NULL;
	envp_to_str_dict(&env_dict, envp);
	exit_status = 0;
	str_dict_add(\
			&env_dict, \
			ft_strdup("?"), \
			ft_itoa(exit_status), \
			free);
	bool newline_flag;
	newline_flag = false;
	while (1)
	{
		char *input;
		char *prompt_str;

		prompt_str = prompt(exit_status);
		input = readline(prompt_str);
		free(prompt_str);
		lctl = device_loop_unit(input, &exit_status, &env_dict, &newline_flag);
		free(input);
		if (lctl == e_break)
			break;
		else if (lctl == e_continue)
			continue;
	}
	str_dict_clear(&env_dict, free, free);
	return (exit_status);
}

char	*none_device_readline()
{
	char		c;
	t_char_list	*lst;
	char		*str;

	lst = NULL;
	while (1)
	{
		c = '\0';
		if (read(STDIN_FILENO, &c, 1) == 0)
			break ;
		char_list_push(&lst, c);
		if (c == '\0' || c == '\n')
			break ;
	}
	str = char_list_to_str(lst);
	char_list_clear(&lst);
	return (str);
}

/// stdin がデバイスでないとき
int	none_device_main_loop(char *envp[])
{
	t_str_dict	*env_dict;
	int			exit_status;
	t_loop_cntl	lctl;

	sig_settig();
	env_dict = NULL;
	envp_to_str_dict(&env_dict, envp);
	exit_status = 0;
	str_dict_add(\
		&env_dict, \
		ft_strdup("?"), \
		ft_itoa(exit_status), \
		free);

	bool newline_flag;
	newline_flag = false;
	while (1)
	{
		char *input;

		input = none_device_readline();
		if (ft_strlen(input) == 0)
			break;
		lctl = device_loop_unit(input, &exit_status, &env_dict, &newline_flag);
		free(input);
		if (lctl == e_break)
			break;
		else if (lctl == e_continue)
			continue;
	}
	str_dict_clear(&env_dict, free, free);
	return (exit_status);
}
