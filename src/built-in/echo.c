/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:22:33 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/12 19:22:33 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "list.h"
#include "strtools.h"
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

static void	nop(void *ptr)
{
	(void)ptr;
}

static char	*as_it_is(char *ptr)
{
	return (ptr);
}

static char	*build_a_string(t_str_list *args, bool new_line_flag)
{
	t_str_list	*str_list;
	char		*tstr;
	char		*rstr;

	str_list = str_list_clone(args, as_it_is);
	tstr = str_list_join(str_list, " ");
	str_list_clear(&str_list, nop);
	if (new_line_flag)
		rstr = ft_strjoin(tstr, "\n");
	else
		rstr = ft_strdup(tstr);
	free(tstr);
	return (rstr);
}

///
///
/// ```bash
/// echo -n hello world
/// ```
///
/// ```bash
/// echo -nnn hello world
/// ```
int	built_in_echo(t_str_list *args, int fd)
{
	int		exit_status;
	bool	newline_flag;
	char	*print_string;

	exit_status = 0;
	newline_flag = true;
	if (str_list_len(args) == 1)
		return (0);
	args = args->next;
	if (ft_streq(str_list_get_elem(args, 0), "-n"))
	{
		newline_flag = false;
		args = args->next;
	}
	print_string = build_a_string(args, newline_flag);
	ft_putstr_fd(print_string, fd);
	free(print_string);
	return (exit_status);
}
