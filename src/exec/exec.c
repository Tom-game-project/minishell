#include "dict.h"
#include "list.h"
#include "parser.h"
#include "utils/utils.h"
#include "exec.h"

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

/// メモ
///
/// - 実際に実行を行う関数の引数にはpidを渡してもいいかもしれない
///     そうすることで、自分が子プロセスか否かを判定できる
///

int exec(t_ast *ast, t_str_dict *envp_dict, int input_fd);

int exec2(t_ast *ast, t_str_dict *envp_dict, int input_fd, int ppid);


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


/// 試作品２つ目
///
/// 引数に、呼び出し元のpidを取ることで、自分が子プロセス内で実行されるかどうかをチェックする
int exec2(t_ast *ast, t_str_dict *envp_dict, int input_fd, int ppid)
{
	int exit_status;

	exit_status = 0;
	str_list_dprint(STDERR_FILENO, ast->arg);
	dprintf(STDERR_FILENO, "^ppid %d, pid %d\n", getppid(), getpid());
	if (ast->ope == e_ope_pipe) // |
		return (pipe_proc(ast, envp_dict, input_fd));
	else if (ast->ope == e_ope_and) // &&
		return (and_proc(ast, envp_dict, input_fd));
	else if (ast->ope == e_ope_or) // ||
		return (or_proc(ast, envp_dict, input_fd));
	else if (ast->ope == e_ope_redirect_i) // <
	{
		// TODO:ファイルを入力として受け取る
		return (0);
	}
	else if (ast->ope == e_ope_none) // 普通のコマンド
	{
		// TODO: built-in関数を判別するためのプログラムをここに追加
		// もしppidが子プロセス中なら
		// この場で実行
		if (ppid == 0)
			exit_status = execve_wrap(ast, envp_dict);
		// もし、子プロセスでなければ
		else
			exit_status = none_proc(ast, envp_dict, input_fd);
		return (exit_status); // TODO exit status を返却するように変更
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
	dprintf(STDERR_FILENO, "@ppid %d, pid %d\n", getppid(), getpid());
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
