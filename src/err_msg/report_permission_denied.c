/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   report_permission_denied.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:00:38 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/30 20:00:38 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "err_msg.h"
#include <stdlib.h>

int	report_permission_denied(char *cmd)
{
	print_error_format_string(cmd, ": Permission denied\n");
	exit(126);
}
