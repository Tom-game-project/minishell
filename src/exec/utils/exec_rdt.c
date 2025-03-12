#include "list.h"
#include "parser.h"
#include "exec.h"
#include "utils.h"
#include "expand_string.h"
#include "test_tools.h"

#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int exec_rdt_proc(
	t_exec_args *args,
	void (*close_fd)(t_exec_args *), // close
	int (*open_func)(char *),// open
	int (*inner_exec)(t_exec_args *, int) //
			// args        , fd
)
{
	char *str;
	int fd;

	close_fd(args);
	str = str_list_get_elem(args->ast->arg, 0);
	if (str == NULL) // NULL
	{
		// TODO:もし見つからなければ
		// ここで見つからないのはありえない
		// Error
	}
	fd = open_func(str);
	if (fd == -1)
	{
		perror("minishell"); // TODO
		return (1);
	}
	inner_exec(args, fd);
	close(fd);
	return (0);
}

/// 文字列がシングルクォーテーション及び、
/// ダブルクォーテーションを含むかどうかを判定する関数
/// ```
/// 
/// ```
static
bool includes_quotation(char *str)
{
	while (*str != '\0')
	{
		if (
			*str == '"' || \
			*str == '\'')
			return (true);
		str++;
	}
	return (false);
}


/// 環境変数展開が必要なheredocについては、
/// 環境変数展開後の文字列を格納した隠しファイルのfdをリストに差し替えて
/// 他の関数は,展開関係なく普通にfdを読んでいるようになる
///
int exec_rdt_proc_heredoc(
	t_exec_args *args,
	void (*close_fd)(t_exec_args *), // close
	int (*inner_exec)(t_exec_args *, int) //
			// args        , fd
)
{
	int fd;
	int new_fd;

	close_fd(args);
	//int_list_print(*args->heredoc_fd_list);
	fd = int_list_pop(args->heredoc_fd_list, 0);
	// TODO:ここに環境変数を展開した
	// 隠しファイルのfdを返す関数を追加する
	if (!includes_quotation(str_list_get_elem(args->ast->arg, 0)))
	{
		// もし、一切クォーテーション、
		// ダブルクォーテーションが
		// ふくまれていなかったら、
		// 環境変数展開の処理をはさみfdをすり替える
		new_fd = heredoc_expand_string_via_fd(fd, *args->envp_dict);
		// dprintf(STDERR_FILENO,"new_fd %d\n", new_fd);
		debug_dprintf(STDERR_FILENO, "close [%d] fd pid [%d]\n", fd, debug_getpid());
		close(fd);
		fd = new_fd;
	}
	if (fd == -1)
	{
		perror("minishell"); // TODO
		return (1);
	}
	inner_exec(args, fd);
	debug_dprintf(STDERR_FILENO, "close [%d] fd pid [%d]\n", fd, debug_getpid());
	close(fd);
	return (0);
}
