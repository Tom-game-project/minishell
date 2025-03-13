#include "built_in.h"
#include "dict.h"
#include "list.h"
#include "parser.h"
#include "exec.h"
#include "expand_string.h"
#include "utils/utils.h"
#include "heredoc/heredoc.h"

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

typedef char *(*t_sd2sfunc)(char *, void *);

/// もとの文字列を、環境変数に基づいて展開する関数
static char *expand_string_wrap_str_free(char *str, t_str_dict *env_dict)
{
	char *rstr;

	rstr = expand_string(str, env_dict);
	free(str);
	return (rstr);
}

/// コマンドが実際に実行される場所
/// 
int run_cmd_proc(t_exec_args *args)
{
	t_built_in tbi;

	if (str_list_len(args->ast->arg) == 0)
		return (0); // TODO とりあえずsegvを防いでいる
	/// 環境変数を展開、展開後のリストをastにもう一度格納
	str_list_map_arg1(
		&(args->ast->arg),
		(t_sd2sfunc) expand_string_wrap_str_free,
		*(args->envp_dict));
	tbi = get_built_in_enum(str_list_get_elem(args->ast->arg, 0));
	if (tbi == e_not_built_in) 
		if (args->ppid == 0)
			return (execve_wrap(args));
		else 
			return (none_proc(args));
	else if (tbi == e_built_in_pwd)
		return (built_in_pwd(args->output_fd));
	else if (tbi == e_built_in_env)
		return (built_in_env(*(args->envp_dict), args->output_fd));
	else if (tbi == e_built_in_cd)
		return (built_in_cd(args->ast->arg, args->envp_dict));
	else if (tbi == e_built_in_export)
		return (built_in_export(args->ast->arg,  args->envp_dict));
	else if (tbi == e_built_in_unset)
		return (built_in_unset(args->ast->arg,  args->envp_dict));
	else if (tbi == e_built_in_exit)
		return (built_in_exit(args->ast->arg));
	else if (tbi == e_built_in_echo)
		return (built_in_echo(args->ast->arg, args->output_fd));
	else
		// unreachable
		return (1);
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
int exec2(t_exec_args *args)
{
	if (args->ast->ope == e_ope_pipe) // |
		return (pipe_proc(args));
	else if (args->ast->ope == e_ope_and) // &&
		return (and_proc(args));
	else if (args->ast->ope == e_ope_or) // ||
		return (or_proc(args));
	else if (args->ast->ope == e_ope_redirect_i) // <
		return (exec_redirect_i_proc(args));
	else if (args->ast->ope == e_ope_redirect_o) // >
		return (exec_redirect_o_proc(args));
	else if (args->ast->ope == e_ope_heredoc_o) // >>
		return (exec_heredoc_o_proc(args));
	else if (args->ast->ope == e_ope_heredoc_i) // <<
		return (exec_heredoc_i_proc(args));
	else if (args->ast->ope == e_ope_paren)     // ()
		return (paren_proc(args));
	else if (args->ast->ope == e_ope_none) // 普通のコマンド
		return (run_cmd_proc(args));
	// dprintf(STDERR_FILENO, "unexpected ope!\n");
	return (1); // exit status を返すように変更
		    // unreachable
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
int exec(t_ast *ast, t_str_dict **envp_dict)
{
	int exit_status;
	t_int_list *heredoc_fd_list;

	heredoc_fd_list = NULL;
	if (heredoc_proc(ast, &heredoc_fd_list)== 130)
	{
		close_all_heredoc_fd(&heredoc_fd_list);
		write(STDOUT_FILENO, &"\n", 1);
		return (130);
	}
	exit_status = exec2(
		&(t_exec_args){
			ast, 
			envp_dict,
			&heredoc_fd_list,
			STDIN_FILENO,
			STDOUT_FILENO,
			-1
		}
	);
	close_all_heredoc_fd(&heredoc_fd_list);
	return (exit_status);
}
