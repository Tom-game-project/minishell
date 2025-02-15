#include "dict.h"
#include "list.h"
#include "parser.h"
#include "exec.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/// exec2関数のテスト
///
/// ```bash
/// sleep 5 | ls -la
/// ```
///
/// `ls -la`が実行されてから`sleep 5`が終わる
///
int test01(int argc, char *argv[], char *envp[])
{
	(void) argc;
	(void) argv;

	t_ast *ast;
	t_str_dict *d;

	t_str_list *l0;
	t_str_list *l1;

	int exit_status;

	l0 = NULL;
	str_list_push(&l0, "sleep");
	str_list_push(&l0, "5");

	l1 = NULL;
	str_list_push(&l1, "ls");
	str_list_push(&l1, "-la");

	ast = &(t_ast) {
		&(t_ast) {
			NULL,
			NULL,
			e_ope_none,
			l0 // sleep 5
		},
		&(t_ast) 
		{
			NULL,
			NULL,
			e_ope_none,
			l1 // ls -la
		},
		e_ope_pipe ,
		NULL,
	};
	d = NULL;
	envp_to_str_dict(&d, envp);
	exit_status = exec(ast, d, STDIN_FILENO);
	dprintf(STDOUT_FILENO, "exit status %d\n", exit_status);
	return (0);
}

/// ```bash
/// make test TEST_FILE=tests/tom_exec_test01.c
/// ```
int main(int argc, char *argv[], char *envp[])
{
	test01(argc, argv ,envp);
	return (0);
}
