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

	cmd = ft_strdup(str_list_get_elem(args->ast->arg, 0)); // 0番目の要素を取り出す
	argv = str_list_to_array(args->ast->arg);
	/// test 用のprint
	//str_list_dprint(STDERR_FILENO, args->ast->arg);
	env_path_node = get_str_dict_by_key(*args->envp_dict, "PATH");
	if (env_path_node == NULL) // 環境変数に`PATH`が見つからない
	{
		free(cmd);
		free(argv);
		// TODO
		// あとで実装する必要がある
		exit(127);
	}
	// PATH環境変数を解析して実行可能なフルパスを検索
	fullpath = get_full_path(cmd, env_path_node->value);
	if (fullpath == NULL)
	{
		// TODO errorメッセージを出力できるようにする
		exit(127); // 実行できるコマンドが見つからない
			   // または実行権限がない
			   // だが、
			   // ここは後で細分化する
			   // ここの処理が終われば、
			   // プロセスが終了し、リソースがすべて開放されるため
			   // ここでは、あえてfreeをしない
	}
	if (access(fullpath, X_OK) == -1) // ファイルの存在が確かめられたら、実行のチェックをする
	{
		exit(126);
	}
	// TODO: 実行すべきpathはこれだけではないはずなので、
	// get_full_pathはあとから更に機能追加が必要
	// TODO WARN
	// fullpathはNULLになって返る可能性がある
	envp = str_dict_to_envp(*args->envp_dict); // 環境変数をexecveに渡せる形に固定する
	dprintf(STDERR_FILENO, "cmd %s running on pid(%d, -> ppid(%d))\n", fullpath, getpid(), getppid());
	execve(fullpath, argv, envp);
	return (1);// ここに到達した場合は不正
}

