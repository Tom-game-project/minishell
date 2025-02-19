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

int exec(t_ast *ast, t_str_dict *envp_dict, int input_fd);

int exec2(t_exec_args *args);

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
	{
		// TODO:ファイルを入力として受け取る
		return (0);
	}
	else if (args->ast->ope == e_ope_paren)
	{
		// TODO: 子プロセスを生成する
		return (0);
	}
	else if (args->ast->ope == e_ope_none) // 普通のコマンド
	{
		// TODO: built-in関数を判別するためのプログラムをここに追加
		//
		// もしppidが子プロセス中なら
		// この場で実行
		if (args->ppid == 0)
			exit_status = execve_wrap(args);
		// もし、子プロセスでなければ
		else
			exit_status = none_proc(args);
		return (exit_status); // TODO exit status を返却するように変更
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
int exec(t_ast *ast, t_str_dict *envp_dict, int input_fd)
{
	int exit_status;
	t_str_list *args;

	args = NULL;
	exit_status = exec2(
		&(t_exec_args){
			ast, 
			envp_dict,
			args,
			input_fd,
			-1
		}
	);
	str_list_clear(&args, free);
	return (exit_status);
}
