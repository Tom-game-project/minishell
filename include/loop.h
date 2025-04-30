/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 21:19:29 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/30 19:47:32 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_H
# define LOOP_H

# include "dict.h"

int	exec_shell_cmd(char *str, t_str_dict **env_dict, int *exit_status);

int	main_loop(char *envp[]);

int	none_device_main_loop(char *envp[]);

#endif
