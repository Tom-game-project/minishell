/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_filefd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 10:30:25 by kaara             #+#    #+#             */
/*   Updated: 2025/01/25 10:30:25 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "pipe.h"

void	setup_filefd(t_ast *ast, t_pipex *pipex)
{
	if (ast->rdtope == e_rdtope_redirect_i)
		from_infile(pipex);
	else if (ast->rdtope == e_rdtope_redirect_o)
		to_outfile(pipex);
}
