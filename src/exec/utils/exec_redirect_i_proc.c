#include "dict.h"
#include "list.h"
#include "parser.h"
#include "exec.h"

#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>


////// レガシー
///bool	read_infile(int *input_fd, char *filename)
///{
///	if (filename)
///	{
///		*input_fd = (close(*input_fd), open(filename, O_RDONLY));
///		if (*input_fd == -1)
///			(perror(filename), exit(1));
///	}
///	return (true);
///}
///
///void	connect_pipe(int d, int input_fd, char *filename)
///{
///	if (input_fd != STDIN_FILENO)
///	{
///		if (d == 0)
///			read_infile(&input_fd, filename);
///		close((dup2(input_fd, STDIN_FILENO), input_fd));
///	}
///}
////// レガシー


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
int exec_redirect_i_proc(t_ast *ast, t_str_dict *envp_dict, int *input_fd)
{
	char *str;
	// t_str_list *args_list;
	(void) envp_dict; // TODO: あとで展開に使う

	// args_list = NULL;
	if (input_fd != STDIN_FILENO)
		close(*input_fd); // すでになにかしらのファイルを
				      // 開いている場合はそれを閉じる
	// ファイルの指定がある場合はここで開く
	str = str_list_get_elem(ast->arg, 0);
	if (str == NULL) // NULL
	{
		// TODO:もし見つからなければ
		// ここで見つからないのはありえない
		// Error
	}
	*input_fd = open(str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*input_fd == -1) // TODO:何かしらの理由でファイルが開けない
	{
		// file open error
		// exit_status 1
		return (1);
	}
	dup2(*input_fd, STDIN_FILENO);
	close(*input_fd);
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
	///
	if (ast->left_ast != NULL && ast->right_ast != NULL) 
		// -- .1
	{
		// str_list_push(&args_list, args_list);
		
	}
	else if (ast->left_ast != NULL)
		// -- .2
	{
	}
	else if (ast->right_ast != NULL) 
		// -- .3
	{

	}
	else
		// -- .4
	{
	}
	/// 以下は後で実装
	exec2(&(t_exec_args)
		{
		
		});
	return (0);
}
