/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   report_command_not_found.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:00:25 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/30 20:00:26 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "err_msg.h"
#include <stdlib.h>

int	report_command_not_found(char *cmd)
{
	print_error_format_string(cmd, ": command not found\n");
	exit(127);
}
