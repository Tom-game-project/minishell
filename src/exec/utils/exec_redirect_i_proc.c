#include "list.h"
#include "parser.h"
#include "exec.h"
#include "libft.h"
#include "utils.h"

#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>


/// 基本的な処理
/// ファイルを書き込み側のパイプにつなげる
///
/// 右astを優先して処理していく,
///
/// 仕様の決定が曖昧なところはあるが、、
///
/// ## 基本的な使い方
///
/// ```bash
/// cat < infile
/// ```
///
/// ```c
/// ast = &(t_ast) {
/// 	&(t_ast) {
/// 		NULL,
/// 		NULL,
/// 		e_ope_none,
/// 		l0 // cat
/// 	},    // left_ast
/// 	NULL, // right_ast
/// 	e_ope_redirect_i, // `<`
/// 	l1, // infile ここは必ず入る
/// };
/// ```
///
/// ```bash
/// < infile cat
/// ```
///
/// ```c
/// ast = &(t_ast) {
/// 	NULL,
/// 	&(t_ast) {
/// 		NULL,
/// 		NULL,
/// 		e_ope_none,
/// 		l0, // cat
/// 	},
/// 	e_ope_redirect_i, // `<`
/// 	l1, // infile
/// };
/// ```
///
/// tests/tom_exec_test10.cに詳しい
///
/// 変則的な例
/// ```bash
/// cat < infile < infile2 -e
/// ```
/// ```bash
/// cat < infile -e < infile
/// ```
///
/// 想定されるastは
/// tests/tom_exec_test10.c
/// tests/tom_exec_test11.c
/// を参照のこと
///
///
/// TODO:
///
/// - input_fdがintのポインタを取る形で大丈夫かどうか
/// - junkなケース
///   - `(cat) < infile -e`
int exec_redirect_i_proc(t_exec_args *args)
	//(t_ast *args->ast, t_str_dict *envp_dict, int *args->input_fd)
{
	char *str;
	t_str_list *args_list;
	int input_fd;

	args_list = NULL;
	if (args->input_fd != STDIN_FILENO)
		close(args->input_fd); // すでになにかしらのファイルを
				           // 開いている場合はそれを閉じる
	// ファイルの指定がある場合はここで開く
	str = str_list_get_elem(args->ast->arg, 0);
	if (str == NULL) // NULL
	{
		// TODO:もし見つからなければ
		// ここで見つからないのはありえない
		// Error
	}
	input_fd = open(str, O_RDONLY, 0644);
	if (input_fd == -1) // TODO:何かしらの理由でファイルが開けない
	{
		// file open error
		// exit_status 1
		return (1);
	}
	//dup2(args->input_fd, STDIN_FILENO);
	// close(args->input_fd);

	///                        // example
	/// left_ast: T right_as:T // `cat < infile -e` -- .1
	/// left_ast: T right_as:F // `cat < infile`    -- .2
	/// left_ast: F right_as:T // `< infile cat -e` -- .3
	/// left_ast: F right_as:F // `< infile`        -- .4
	/// 
	/// # WARNNING
	///
	/// 不正な文法構造を持っていた場合は正しく処理できません
	///
	/// # 処理
	///
	/// e_ope_none以外に正しく処理が実行される例
	///
	if (args->ast->left_ast != NULL && args->ast->left_ast->ope == e_ope_none)
		// -- .2
		str_list_concat(
				&args_list,
			       	str_list_clone(
					args->ast->left_ast->arg,
				       	ft_strdup));
	//if (args->ast->right_ast != NULL && args->ast->right_ast->ope == e_ope_none) 
	//	// -- .3
	//	str_list_concat(
	//			&args_list,
	//		       	str_list_clone(
	//				ast->right_ast->arg,
	//			       	ft_strdup));
	/// 実行
	//if (args->ast->left_ast != NULL)
	//	exec2(&(t_exec_args)
	//	{
	//	    args->ast->left_ast,
	//	    args->envp_dict,
	//	    args_list,
	//	    STDIN_FILENO, 
	//	    -1 // 子プロセスを生み出すため
	//	});
	if (args->ast->right_ast != NULL)
		exec2(&(t_exec_args)
		{
		    args->ast->right_ast,
		    args->envp_dict,
		    args_list,
		    input_fd, 
		    -1 // 子プロセスを生み出すため
		});
	else if (args->ast->left_ast != NULL)
	{
		exec2(&(t_exec_args)
		{
		    args->ast->left_ast,
		    args->envp_dict,
		    NULL,
		    input_fd,
		    -1 // 子プロセスを生み出すため
		});
	} // TODO:考える
	close(input_fd);
	return (0);
}
