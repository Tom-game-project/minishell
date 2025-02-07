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

#include "pipe.h"

void	setup_filefd(t_pipex *pipex, int cmdc_i)
{
	if (cmdc_i == 0)
		from_infile(pipex);
	else if (cmdc_i == pipex->cmdc - 1)
		to_outfile(pipex);
}
