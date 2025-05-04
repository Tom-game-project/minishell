/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   report_parser_syntax_error.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:36:16 by tmuranak          #+#    #+#             */
/*   Updated: 2025/05/03 18:37:33 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	report_parser_syntax_error(void)
{
	ft_putstr_fd("minishell : parser : syntax error\n", STDERR_FILENO);
	return (1);
}
