#include "dict.h"
#include "list.h"
#include "parser.h"
#include "exec.h"
#include <stdio.h>
#include <stdlib.h>

/// exec2関数のテスト
///
/// ```bash
/// sleep 100 | ls -la
/// ```
///
/// `ls -la`が実行されてから`sleep 100`が終わる
///
int test01(int argc, char *argv[], char *envp[])
{
	(void) argc;
	(void) argv;

	t_ast *ast;
	t_str_dict *d;

	t_str_list *l0;
	t_str_list *l1;

	l0 = NULL;
	str_list_push(&l0, "sleep");
	str_list_push(&l0, "100");

	l1 = NULL;
	str_list_push(&l1, "ls");
	str_list_push(&l1, "-la");
	//str_list_push(&l1, "world");

	//str_list_push(&l2, "echo");
	//str_list_push(&l2, "$(ls -la)");
	// test case: echo hello | cat
	ast = &(t_ast) {
		&(t_ast) {
			NULL,
			NULL,
			e_ope_none,
			l0 // echo hello
		},
		&(t_ast) 
		{
			NULL,
			NULL,
			e_ope_none,
			l1 // cat
		},
		e_ope_pipe ,
		NULL,
		NULL
	};
	d = NULL;
	envp_to_str_dict(&d, envp);
	exec2(ast, d, STDIN_FILENO, -1);
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
