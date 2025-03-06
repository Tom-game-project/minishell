#include "dict.h"
#include "exec.h"
#include "list.h"
#include "parser.h"
#include "path.h"
#include "libft.h"

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

/// TODO あとで関数の名前を変更する
static
int print_error_msg(char *cmd)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	exit(127);
}

static
int print_error_msg2(char *cmd)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": Permission denied\n", STDERR_FILENO);
	exit(126);
}


/// 実行に必要なコマンド列を、生成する
/// 全く新しい領域が確保されるので、返り値は解放が必要

/// 扱いやすい引数を渡すことで実行できるexecve
/// この関数では以下の処理を行う
/// - 環境変数の展開
/// - $()展開 (この関数が更に子プロセスを生じさせる可能性がある)
/// - もし、args -> argsが空でなければ今のコマンドとくっつけて実行する
int execve_wrap(t_exec_args *args)
{
	char *fullpath;
	char *cmd;
	char **argv;
	char **envp;
	t_str_dict *env_path_node;

	cmd = ft_strdup(str_list_get_elem(args->ast->arg, 0));
	argv = str_list_to_array(args->ast->arg);
	env_path_node = get_str_dict_by_key(*args->envp_dict, "PATH");
	if (env_path_node == NULL) // 環境変数に`PATH`が見つからない
	{
		print_error_msg(cmd);
	}
	// PATH環境変数を解析して実行可能なフルパスを検索
	fullpath = get_full_path(cmd, env_path_node->value);
	if (fullpath == NULL)
	{
		print_error_msg(cmd);
	}
	if (access(fullpath, X_OK) == -1)
	{
		print_error_msg2(cmd);
	}
	envp = str_dict_to_envp(*args->envp_dict);
	dprintf(STDERR_FILENO, "cmd %s running on pid(%d) ppid(%d)\n", fullpath, getpid(), getppid());
	execve(fullpath, argv, envp);
	return (1);// ここに到達した場合は不正
}

