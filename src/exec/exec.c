#include "dict.h"
#include "list.h"
#include "parser.h"
#include "path.h"
#include "exec.h"

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

/// メモ
///
/// 実際に実行を行う関数の引数にはpidを渡してもいいかもしれない
///
/// そうすることで、自分が子プロセスか否かを判定できる

#define BUF_SIZE 2
// (パイプを)読む
#define PIPE_READ 0
// (パイプに)書き込む
#define PIPE_WRITE 1

int exec(t_ast *ast, t_str_dict *envp_dict, int input_fd);

int exec2(t_ast *ast, t_str_dict *envp_dict, int input_fd, int ppid);

/// 扱いやすい引数を渡すことで実行できるexecve
int execve_wrap(t_ast *ast, t_str_dict *envp_dict)
{
	char *fullpath;
	char *cmd;
	char **argv;
	char **envp;
	t_str_dict *env_path_node;

	cmd = str_list_get_elem(ast->arg, 0); // 0番目の要素を取り出す
	argv = str_list_to_array(ast->arg);
	env_path_node = get_str_dict_by_key(envp_dict, "PATH");
	if (env_path_node == NULL) // 環境変数に`PATH`が見つからない
	{
		// TODO
		// あとで実装する必要がある
		exit(1);
	}
	// PATH環境変数を解析して実行可能なフルパスを検索
	fullpath = get_full_path(cmd, env_path_node->value);
	// TODO: 実行すべきpathはこれだけではないはずなので、
	// get_full_pathはあとから更に機能追加が必要
	// TODO WARN
	// fullpathはNULLになって返る可能性がある
	envp = str_dict_to_envp(envp_dict); // 環境変数をexecveに渡せる形に固定する
	dprintf(STDERR_FILENO, "cmd %s running\n", fullpath);
	execve(fullpath, argv, envp);
	return (1);// ここに到達した場合は不正
}

/// exit_statusを返却する
int pipe_proc(t_ast *ast, t_str_dict *envp_dict, int input_fd)
{
	int pid;
	int pipe_fd[2];
	int pre_exit_status;

	if (pipe(pipe_fd) == -1)
		// パイプの生成に失敗
		return (1);
	pid = fork();
	if (pid == 0)
	{ // 子
		if (input_fd != STDIN_FILENO)
		{
			dup2(input_fd, STDIN_FILENO);
			close(input_fd);
		}
		close(pipe_fd[PIPE_READ]);
		dup2(pipe_fd[PIPE_WRITE], STDOUT_FILENO);
		close(pipe_fd[PIPE_WRITE]);
		exec2(ast->left_ast, envp_dict, input_fd, pid); // 
		exit(0);
	} // 親
	close(pipe_fd[PIPE_WRITE]);
	if (input_fd != STDIN_FILENO)
		close(input_fd);
	exec2(ast->right_ast, envp_dict, pipe_fd[PIPE_READ], pid);
	waitpid(pid, &pre_exit_status, WUNTRACED);
	return (WEXITSTATUS(pre_exit_status));
}

/// 実行可能な状態であり、かつ、
/// 自分自身が子プロセス中に入っていない場合(親プロセスから)実行される関数
int none_proc(t_ast *ast, t_str_dict *envp_dict,int input_fd)
{
	int pid;
	int status;
	int pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		return (-1);
	pid = fork();
	if (pid == 0)
	{
		if (input_fd != STDIN_FILENO)
		{
			dup2(input_fd, STDIN_FILENO);
			close(input_fd);
		}
		close(pipe_fd[PIPE_READ]);
		dup2(pipe_fd[PIPE_WRITE], STDOUT_FILENO);
		close(pipe_fd[PIPE_WRITE]);
		execve_wrap(ast, envp_dict);
		return(1);
	}
	else
	{
		close(pipe_fd[PIPE_WRITE]);// 子プロセスに伝えることはない						
		fd_write(pipe_fd[PIPE_READ]);
		waitpid(pid, &status, WUNTRACED);
		close(pipe_fd[PIPE_READ]);
		return (WEXITSTATUS(status));
	}

}

/// 試作品２つ目
///
/// 引数に、呼び出し元のpidを取ることで、自分が子プロセス内で実行されるかどうかをチェックする
int exec2(t_ast *ast, t_str_dict *envp_dict, int input_fd, int ppid)
{

	//dprintf(STDERR_FILENO, "cmd %s\n", ast->cmd);
	str_list_dprint(STDERR_FILENO, ast->arg);
	dprintf(STDERR_FILENO, "ppid %d, pid %d\n", getppid(), getpid());
	if (ast->ope == e_ope_pipe)
	{
		pipe_proc(ast, envp_dict, input_fd);
		return (1);
	}
	else if (ast->ope == e_ope_none) // 普通のコマンド
	{
		// もしppidが子プロセス中なら
		// この場で実行
		if (ppid == 0)
		{
			execve_wrap(ast, envp_dict);
		}
		// もし、子プロセスでなければ
		else
			none_proc(ast, envp_dict, input_fd);
		return (0); // TODO exit status を返却するように変更
	}
	else
	{
		dprintf(STDERR_FILENO, "unexpected ope!\n");
		return (1); // exit status を返すように変更
	}

}

//////////////////////////////////////////////////////////////////////

int exec(t_ast *ast, t_str_dict *envp_dict, int input_fd)
{
	int pipe_fd[2];

	//dprintf(STDERR_FILENO, "cmd %s\n", ast->cmd);
	str_list_dprint(STDERR_FILENO, ast->arg);
	dprintf(STDERR_FILENO, "ppid %d, pid %d\n", getppid(), getpid());
	//
	if (ast->ope == e_ope_pipe)
	{
		//exec(ast->left_ast, envp_dict, input_fd);
		//exec(ast->right_ast, envp_dict, input_fd);
		return (1);
	}
	else if (ast->ope == e_ope_none) // 普通のコマンド
	{
		int pid;
		int status;

		if (pipe(pipe_fd) == -1)
			return (-1);
		pid = fork();
		if (pid == 0)
		{
			if (input_fd != STDIN_FILENO)
			{
				dup2(input_fd, STDIN_FILENO);
				close(input_fd);
			}
			close(pipe_fd[PIPE_READ]);
			dup2(pipe_fd[PIPE_WRITE], STDOUT_FILENO);
			close(pipe_fd[PIPE_WRITE]);
			execve_wrap(ast, envp_dict);
			return(1);
		}
		else
		{
			close(pipe_fd[PIPE_WRITE]);// 子プロセスに伝えることはない						
			fd_write(pipe_fd[PIPE_READ]);
			waitpid(pid, &status, WUNTRACED);
			close(pipe_fd[PIPE_READ]);
			return (WEXITSTATUS(status));
		}
	}
	else
	{
		dprintf(STDERR_FILENO, "unexpected ope!\n");
		return (1);
	}
}
