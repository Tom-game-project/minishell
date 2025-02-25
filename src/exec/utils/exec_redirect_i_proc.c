#include "list.h"
#include "parser.h"
#include "exec.h"
#include "utils.h"

#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

/// infileでの基本的な動作
///
/// 
int exec_redirect_i_proc(t_exec_args *args)
{
	char *str;
	int input_fd;

	if (args->input_fd != STDIN_FILENO){
		close(args->input_fd); // すでになにかしらのファイルを
				           // 開いている場合はそれを閉じる
	}
	// ファイルの指定がある場合はここで開く
	// 引数は必ず一つ
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
		//return (1);
		perror("minishell"); // TODO
	}

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
	/// もし左側にコマンド片がある場合
	if (args->ast->right_ast != NULL)
	{
		exec2(&(t_exec_args)
		{
		    args->ast->right_ast,
		    args->envp_dict,
		    NULL,
		    input_fd, 
		    args->output_fd, 
		    -1 // 子プロセスを生み出すため
		});
	}
	else if (args->ast->left_ast != NULL) // （右がなく）かつ（左アリ）
	{
		exec2(&(t_exec_args)
		{
		    args->ast->left_ast,
		    args->envp_dict,
		    NULL,
		    input_fd, 
		    args->output_fd, 
		    -1 // 子プロセスを生み出すため
		}
		);
	}
	return (0);
}
