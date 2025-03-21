/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_or_proc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:53:00 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/21 18:53:11 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "utils.h"
#include <sys/wait.h>
#include <unistd.h>

#include <stdbool.h>

static bool	exit_status_has_err(int exit_status)
{
	return (exit_status != 0);
}

int	or_proc(t_exec_args *args)
{
	return (sequential_proc(args, exit_status_has_err));
}
