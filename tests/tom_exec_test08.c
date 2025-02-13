#include "list.h"
#include "parser.h"
#include "exec.h"
#include <stdio.h>

/// exec2 のテスト
///
/// `||`と同じように挙動するかどうかを確かめる
///
/// ```bash
/// make test TEST_FILE=tests/tom_exec_test08.c
/// ```
///
/// ```bash
/// < infile cat
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
	str_list_push(&l0, "cat");

	l1 = NULL;
	str_list_push(&l1, "infile");

	ast = &(t_ast) {
		NULL,
		&(t_ast) 
		{
			NULL,
			&(t_ast) {
				NULL,
				NULL,
				e_ope_none,
				l0 // cat
			},
			e_ope_none,
			l1 // infile
		},
		e_ope_redirect_i, // `<`
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
/// make test TEST_FILE=tests/tom_exec_test07.c
/// ```
int main(int argc, char *argv[], char *envp[])
{
	test00(argc, argv ,envp);
	return (0);
}
