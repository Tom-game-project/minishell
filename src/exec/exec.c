/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:07:07 by tmuranak          #+#    #+#             */
/*   Updated: 2025/04/21 20:55:14 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "dict.h"
#include "list.h"
#include "parser.h"
#include "exec.h"
#include "utils/utils.h"
#include "heredoc/heredoc.h"

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

#include "sig.h"
#include "strtools.h"

/// ビルトインコマンドへ振り分ける関数
///
/// argsは環境変数展開後のものである必要がある
int run_cmd_proc_switcher2(
	t_exec_args *exec_args,
       	t_str_list *args,
       	t_built_in	tbi
)
{
	if (tbi == e_not_built_in)
	{
		if (exec_args->ppid == 0)
			return (execve_wrap2(args, *exec_args->envp_dict));
		else
			return (none_proc2(exec_args->input_fd, exec_args->output_fd, args, *exec_args->envp_dict));
	}
	else if (tbi == e_built_in_pwd)
		return (built_in_pwd(exec_args->output_fd));
	else if (tbi == e_built_in_env)
		return (built_in_env(*(exec_args->envp_dict), exec_args->output_fd));
	else if (tbi == e_built_in_cd)
		return (built_in_cd(args, exec_args->envp_dict));
	else if (tbi == e_built_in_export)
		return (built_in_export(args, exec_args->envp_dict));
	else if (tbi == e_built_in_unset)
		return (built_in_unset(args, exec_args->envp_dict));
	else if (tbi == e_built_in_exit)
		return (built_in_exit(args, *exec_args->envp_dict));
	else if (tbi == e_built_in_echo)
		return (built_in_echo(args, exec_args->output_fd));
	else
		return (1);
}

static bool is_junk(t_anytype elem)
{
	return (ft_streq(elem.str, ""));
}


/// コマンドが実際に実行される場所
/// 
int	run_cmd_proc(t_exec_args *exec_args)
{
	t_built_in	tbi;
	t_str_list	*args;
	int exit_status;
	t_str_list *junk;

	if (str_list_len(exec_args->ast->arg) == 0)
		return (0);
	args = expand_env_vars(exec_args->ast->arg, *exec_args->envp_dict);
	junk = void_list_filter(&args, is_junk);
	str_list_clear(&junk, free);
	tbi = get_built_in_enum(str_list_get_elem(exec_args->ast->arg, 0));
	exit_status = run_cmd_proc_switcher2(exec_args, args, tbi);
	str_list_clear(&args, free);
	return (exit_status);
}

/// exec2 関数に引数を渡すためだけに使います
/// 試作品２つ目
///
/// 引数に、呼び出し元のpidを取ることで、自分が子プロセス内で実行されるかどうかをチェックする
///
/// 関数の呼び出し方に気をつけて使う
/// ```c
///
/// ```
int	exec2(t_exec_args *args)
{
	if (args->ast->ope == e_ope_pipe)
		return (pipe_proc(args));
	else if (args->ast->ope == e_ope_and)
		return (and_proc(args));
	else if (args->ast->ope == e_ope_or)
		return (or_proc(args));
	else if (args->ast->ope == e_ope_redirect_i)
		return (exec_redirect_i_proc(args));
	else if (args->ast->ope == e_ope_redirect_o)
		return (exec_redirect_o_proc(args));
	else if (args->ast->ope == e_ope_heredoc_o)
		return (exec_heredoc_o_proc(args));
	else if (args->ast->ope == e_ope_heredoc_i)
		return (exec_heredoc_i_proc(args));
	else if (args->ast->ope == e_ope_paren)
		return (paren_proc(args));
	else if (args->ast->ope == e_ope_none)
		return (run_cmd_proc(args));
	return (1);
}

/// この処理に入る時点で、junkなケースが弾かれていることを期待する
/// 不正な文法を許容したastに対する処理はうまく行かない
///
/// 例えば、
/// ```bash
/// (cat) < infile -e
/// ```
/// これは文法のエラーになる
/// 
int	exec(t_ast *ast, t_str_dict **envp_dict)
{
	int			exit_status;
	t_int_list	*heredoc_fd_list;

	set_sigint_handle_sig();
	heredoc_fd_list = NULL;
	if (heredoc_proc(ast, &heredoc_fd_list) == 130)
	{
		close_all_heredoc_fd(&heredoc_fd_list);
		write(STDOUT_FILENO, &"\n", 1);
		return (130);
	}
	set_sigint_ignore();
	exit_status = exec2(\
		&(t_exec_args){
			ast, \
			envp_dict, \
			&heredoc_fd_list, \
			STDIN_FILENO, \
			STDOUT_FILENO, \
			-1
		});
	close_all_heredoc_fd(&heredoc_fd_list);
	return (exit_status);
}
