/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_checker_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:56:00 by kaara             #+#    #+#             */
/*   Updated: 2025/05/03 14:56:03 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast_checker.h"

bool	is_enum_rdtope(t_operator ope)
{
	return (
		ope == e_ope_redirect_i
		|| ope == e_ope_redirect_o
		|| ope == e_ope_heredoc_i
		|| ope == e_ope_heredoc_o
	);
}
