/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:23:29 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/30 19:48:55 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_MSG_H
# define ERR_MSG_H

void	print_error_format_string(char *cmd, char *msg);

int		report_command_not_found(char *cmd);

int		report_is_a_directory(char *cmd);

int		report_no_such_file_or_directory(char *cmd);

int		report_permission_denied(char *cmd);

// cd


int report_cd_too_many_arguments(void);
int report_cd_oldpwd_not_set(void);
int report_cd_home_not_set(void);

#endif
