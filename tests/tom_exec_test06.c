#include "list.h"
#include "parser.h"
#include "exec.h"
#include <stdio.h>

/// exec2 のテスト
///
/// `||`と同じように挙動するかどうかを確かめる
///
/// ```bash
/// make test TEST_FILE=tests/tom_exec_test06.c
/// ```
///
/// ```bash
/// true || echo world success!
/// ```
int test00(int argc, char *argv[], char *envp[])
{
	(void) argc;
	(void) argv;
	
	int exit_status;

	t_ast *ast;
	t_str_dict *d;

	t_str_list *l0;
	t_str_list *l1;

	l0 = NULL;
	str_list_push(&l0, "false");

	l1 = NULL;
	str_list_push(&l1, "echo");
	str_list_push(&l1, "world");
	str_list_push(&l1, "success!");

	ast = &(t_ast) {
		&(t_ast) {
			NULL,
			NULL,
			e_ope_none,
			NULL,
			l0 // `true`
		},
		&(t_ast) 
		{
			NULL,
			NULL,
			e_ope_none,
			NULL,
			l1 // `echo world success!
		},
		e_ope_or, // `||`
		NULL,
		NULL
	};
	d = NULL;
	envp_to_str_dict(&d, envp);
	exit_status = exec2(ast, d, STDIN_FILENO, -1);
	printf("exit status (%d)\n", exit_status);
	return (exit_status);
}


/// ```bash
/// make test TEST_FILE=tests/tom_exec_test06.c
/// ```
int main(int argc, char *argv[], char *envp[])
{
	test00(argc, argv ,envp);
	return (0);
}
