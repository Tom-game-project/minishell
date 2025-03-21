/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_and_proc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:46:26 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/21 18:46:48 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "utils.h"
#include <sys/wait.h>
#include <unistd.h>

#include <stdbool.h>

static bool	exit_status_is_ok(int exit_status)
{
	return (exit_status == 0);
}

int	and_proc(t_exec_args *args)
{
	return (sequential_proc(args, exit_status_is_ok));
}
