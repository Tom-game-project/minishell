/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:04:13 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/21 19:06:54 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "exec.h"

int	execve_wrap(t_exec_args *args);

int	execve_wrap2(t_str_list *args, t_str_dict *envp_dict);

int	and_proc(t_exec_args *args);

int	none_proc(t_exec_args *args);

int	none_proc2(int input_fd, int output_fd, t_str_list *args, t_str_dict *envp_dict);

int	or_proc(t_exec_args *args);

int	pipe_proc(t_exec_args *args);

int	exec_redirect_i_proc(t_exec_args *args);

int	exec_redirect_o_proc(t_exec_args *args);

int	exec_heredoc_i_proc(t_exec_args *args);

int	exec_heredoc_o_proc(t_exec_args *args);

int	paren_proc(t_exec_args *args);

int	sequential_proc(t_exec_args *args, bool (*f)(int));

int	exec_rdt_proc(\
	t_exec_args *args, \
	void (*close_fd)(t_exec_args *), \
	int (*open_func)(char *), \
	int (*inner_exec)(t_exec_args *, int)\
);

int	exec_rdt_proc_heredoc(\
	t_exec_args *args, \
	void (*close_fd)(t_exec_args *), \
	int (*inner_exec)(t_exec_args *, int) \
);

int	consume_fd(int heredoc_c, t_int_list **heredoc_fd_list);
#endif
