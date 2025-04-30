/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   report_no_such_file_or_directory.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:00:34 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/30 20:00:48 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "err_msg.h"
#include <stdlib.h>

/// TODO
int	report_no_such_file_or_directory(char *cmd)
{
	print_error_format_string(cmd, ": Is not a file or directory\n");
	exit(126);
}
