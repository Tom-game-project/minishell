/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   report_is_a_directory.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:00:30 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/30 20:00:31 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "err_msg.h"
#include <stdlib.h>

int	report_is_a_directory(char *cmd)
{
	print_error_format_string(cmd, ": Is a directory\n");
	exit(126);
}
