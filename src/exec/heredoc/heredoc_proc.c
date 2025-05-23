/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_proc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:08:54 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/21 18:09:49 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "list.h"
#include "libft.h"
#include "strtools.h"
#include "heredoc.h"
#include "path.h"

#include <stdlib.h>

static int	heredoc_unit_proc(\
	t_ast *ast, t_int_list **heredoc_fd_list, int rw_fd[2])
{
	char	*str;
	char	*strl;
	char	*strl2;
	int		exit_status;

	str = str_list_get_elem(ast->arg, 0);
	strl = ft_strjoin(str, "\n");
	strl2 = remove_quotations(strl);
	free(strl);
	if (create_shadow_file(rw_fd) == -1)
		return (1);
	exit_status = read_heredocline2(strl2, rw_fd[1]);
	free(strl2);
	close(rw_fd[1]);
	int_list_push(heredoc_fd_list, rw_fd[0]);
	return (exit_status);
}

///
///
int	heredoc_proc(t_ast *ast, t_int_list **heredoc_fd_list)
{
	int	rw_fd[2];
	int	exit_status;

	exit_status = 0;
	if (ast->ope == e_ope_heredoc_i)
	{
		exit_status = heredoc_unit_proc(ast, heredoc_fd_list, rw_fd);
		if (exit_status != 0)
			return (exit_status);
	}
	if (ast->left_ast != NULL)
	{
		exit_status = heredoc_proc(ast->left_ast, heredoc_fd_list);
		if (exit_status != 0)
			return (exit_status);
	}
	if (ast->right_ast != NULL)
	{
		exit_status = heredoc_proc(ast->right_ast, heredoc_fd_list);
		if (exit_status != 0)
			return (exit_status);
	}
	return (exit_status);
}
