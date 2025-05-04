/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_checker_result.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:00:08 by kaara             #+#    #+#             */
/*   Updated: 2025/05/03 15:00:21 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast_checker.h"
#include "test_tools.h"
#include <unistd.h>
#include "libft.h"

bool	print_checker_result(t_syntax_result result)
{
	if (result == e_syntax_ok)
		return (true);
	else if (result == e_ctl_near_unexpected_token_and)
		ft_putstr_fd("minishell : near_unexpected_token_and\n", STDERR_FILENO);
	else if (result == e_ctl_near_unexpected_token_or)
		ft_putstr_fd("minishell : near_unexpected_token_or\n", STDERR_FILENO);
	else if (result == e_rdt_near_unexpected_token_pipe)
		ft_putstr_fd("minishell : near_unexpected_token_pipe\n", STDERR_FILENO);
	else if (result == e_rdt_near_unexpected_token_newline)
		ft_putstr_fd("minishell : near_unexpected_token_newline\n",
			STDERR_FILENO);
	else if (result == e_rdt_near_unexpected_token_rdt)
		ft_putstr_fd("minishell : near_unexpected_token_rdt\n",
			STDERR_FILENO);
	else if (result == e_syntax_near_unexpected_token_string)
		ft_putstr_fd("minishell : near_unexpected_token_string\n",
			STDERR_FILENO);
	return (false);
}
