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

# include "parser.h"
# include "dict.h"
# include <unistd.h>
# include <stdbool.h>

// (パイプを)読む
# define PIPE_READ 0
// (パイプに)書き込む
# define PIPE_WRITE 1

// src/exec/exec.c

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

int		fd_write(int from_fd, int to_fd);

// for test 
// アスタリスク

t_str_list *split_path_by_slash(char *path);

bool is_same_string(t_char_list *target, t_str_list *rule_lst);

//t_str_list *filter_paths_by_rule(t_str_list **node, char *rule_str);

t_str_list *filter_paths_by_rule_wrap(
	t_str_list **curr_lst, 
	char *rule);

//char *gen_formatted_asterisk_rule(char *raw_rule);

t_str_list *dir_walker(t_str_list **path, t_str_list *splited_path);

t_str_list *rule_to_lst(char *rule_str);

bool comb2_any(
	t_char_list *lst,
       	t_str_list *rule_lst,
       	bool (*f)(
		t_char_list *str_lst,
	       	t_str_list *rule_list));

#endif
