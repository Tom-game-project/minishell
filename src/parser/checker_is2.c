/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_is2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:31:35 by kaara             #+#    #+#             */
/*   Updated: 2025/05/03 15:32:07 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

bool	is_control_operators(char *element)
{
	if (ft_strncmp(element, "&&", 2) == 0)
		return (true);
	if (ft_strncmp(element, "||", 2) == 0)
		return (true);
	return (false);
}

bool	is_redirect_operators(char *element)
{
	if (ft_strncmp(element, "<<", 2) == 0)
		return (true);
	if (ft_strncmp(element, ">>", 2) == 0)
		return (true);
	if (ft_strncmp(element, "<", 1) == 0)
		return (true);
	if (ft_strncmp(element, ">", 1) == 0)
		return (true);
	if (ft_strncmp(element, "|", 1) == 0)
		return (true);
	return (false);
}

bool	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}
