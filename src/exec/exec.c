#include "built_in.h"
#include "dict.h"
#include "list.h"
#include "parser.h"
#include "utils/utils.h"
#include "exec.h"
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

/// メモ
///
/// - 実際に実行を行う関数の引数にはpidを渡してもいいかもしれない
///     そうすることで、自分が子プロセスか否かを判定できる
///

// # menu
//enum    e_operato
//{
//	e_ope_none,
//	e_ope_and,// &&
//	e_ope_or,// ||
//	e_ope_redirect_i,// < ファイルを入力
//	e_ope_redirect_o,// > ファイルを出力
//	e_ope_heredoc_i,// << here doc
//	e_ope_heredoc_o,// >> ファイルの末尾に追記
//	e_ope_pipe// |
//};

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
	int exit_status;

	exit_status = 0;
	str_list_dprint(STDERR_FILENO, args->ast->arg);
	dprintf(STDERR_FILENO, "^ppid %d, pid %d\n", getppid(), getpid());
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
	else if (args->ast->ope == e_ope_paren)
	{
		// TODO: 子プロセスを生成する
		paren_proc(args);
		return (0);
	}
	else if (args->ast->ope == e_ope_none) // 普通のコマンド
	{
		// TODO: built-in関数を判別するためのプログラムをここに追加
		//
		t_built_in tbi;
		if (str_list_len(args->ast->arg) == 0)
			return (0); // TODO とりあえずsegvを防いでいる
		tbi = get_built_in_enum(str_list_get_elem(args->ast->arg, 0));
		if (tbi == e_not_built_in)
		{
			if (args->ppid == 0)
				exit_status = execve_wrap(args);
			else 
				exit_status = none_proc(args);
			return (exit_status); // TODO exit status を返却するように変更
		}
		else if (tbi == e_built_in_pwd)
		{
			return (built_in_pwd());
		}
		else if (tbi == e_built_in_env)
		{
			return (built_in_env(*(args->envp_dict)));
		}
		else if (tbi == e_built_in_cd)
		{
			return (built_in_cd(args->ast->arg));
		}
		else if (tbi == e_built_in_export)
		{
			return (built_in_export(args->ast->arg,  args->envp_dict));
		}
		else if (tbi == e_built_in_unset)
		{
			return (built_in_unset(args->ast->arg,  args->envp_dict));
		}
		else
		{
			// unreachable
			return (1);
		}
	}
	else
	{
		dprintf(STDERR_FILENO, "unexpected ope!\n");
		return (1); // exit status を返すように変更
	}
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
	t_str_list *args;

	args = NULL;
	exit_status = exec2(
		&(t_exec_args){
			ast, 
			envp_dict,
			args,
			STDIN_FILENO,
			STDOUT_FILENO,
			-1
		}
	);
	str_list_clear(&args, free);
	return (exit_status);
}
