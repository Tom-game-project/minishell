# ifndef EXEC_H
#define EXEC_H

# include "parser.h"
# include "dict.h"
# include <unistd.h>
# include <stdbool.h>

#define BUF_SIZE 2

// (パイプを)読む
#define PIPE_READ 0
// (パイプに)書き込む
#define PIPE_WRITE 1


// src/exec/exec.c

int exec(t_ast *ast, t_str_dict *envp_dict, int input_fd);

/// exec2 関数に引数を渡すためだけに使います
typedef struct s_exec_args t_exec_args;
struct s_exec_args
{
	t_ast *ast; // 抽象構文木
       	t_str_dict *envp_dict; // 環境変数リスト
	t_str_list *args; // コマンドと引数を格納するリスト
       	int input_fd; // input_fd
       	int ppid; // 親のプロセスid
};

int exec2(t_exec_args *args);

//checker.c
// bool    check_logical_operator(t_ast *ast, int exit_status);

// bool	check_update_arg(t_ast *ast);

int fd_write(int fd);

# endif
