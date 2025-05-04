/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str2ope.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 21:31:15 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/21 21:31:26 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "strtools.h"

t_operator	str2ope(char *str)
{
	if (ft_streq(str, "<<"))
		return (e_ope_heredoc_i);
	else if (ft_streq(str, ">>"))
		return (e_ope_heredoc_o);
	else if (ft_streq(str, "|"))
		return (e_ope_pipe);
	else if (ft_streq(str, "||"))
		return (e_ope_or);
	else if (ft_streq(str, "&&"))
		return (e_ope_and);
	else if (ft_streq(str, "<"))
		return (e_ope_redirect_i);
	else if (ft_streq(str, ">"))
		return (e_ope_redirect_o);
	else
		return (e_ope_none);
}
