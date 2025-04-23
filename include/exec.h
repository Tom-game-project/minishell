/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:47:31 by tmuranak          #+#    #+#             */
/*   Updated: 2025/03/12 19:49:55 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

#include "list.h"
# include "parser.h"
# include "dict.h"
# include <unistd.h>
# include <stdbool.h>

// (パイプを)読む
# define PIPE_READ 0
// (パイプに)書き込む
# define PIPE_WRITE 1

// src/exec/exec.c


typedef char                                *(*t_sd2sfunc)(char *, void *);

int		exec(t_ast *ast, t_str_dict **envp_dict);

/// exec2 関数に引数を渡すためだけに使います
typedef struct s_exec_args	t_exec_args;
struct s_exec_args
{
	t_ast		*ast;
	t_str_dict	**envp_dict;
	t_str_list	**heredoc_fd_list;
	int			input_fd;
	int			output_fd;
	int			ppid;
};

int		exec2(t_exec_args *args);

//checker.c
// bool    check_logical_operator(t_ast *ast, int exit_status);

// bool	check_update_arg(t_ast *ast);

#endif
