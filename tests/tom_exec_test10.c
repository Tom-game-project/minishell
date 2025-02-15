#include "list.h"
#include "parser.h"
#include "exec.h"
#include <stdio.h>

/// exec2 のテスト
// test07のastの代替案


/// exec2 のテスト
///
/// `<`の処理のテスト
///
/// ```bash
/// make test TEST_FILE=tests/tom_exec_test10.c
/// ```
///
/// ```bash
/// cat < infile
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
		&(t_ast) {
			NULL,
			NULL,
			e_ope_none,
			l0 // cat
		},
		NULL,
		e_ope_redirect_i, // `<`
		l1, // infile
	};
	d = NULL;
	envp_to_str_dict(&d, envp);
	exit_status = exec(ast, d, STDIN_FILENO);
	printf("exit status (%d)\n", exit_status);
	return (exit_status);
}


/// exec2 のテスト
///
/// `<`の処理のテスト
///
/// ```bash
/// make test TEST_FILE=tests/tom_exec_test10.c
/// ```
///
/// ```bash
/// < infile cat
/// ```
int test01(int argc, char *argv[], char *envp[])
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
		&(t_ast) {
			NULL,
			NULL,
			e_ope_none,
			l0, // cat
		},
		e_ope_redirect_i, // `<`
		l1, // infile
	};
	d = NULL;
	envp_to_str_dict(&d, envp);
	exit_status = exec(ast, d, STDIN_FILENO);
	printf("exit status (%d)\n", exit_status);
	return (exit_status);
}



/// ```bash
/// make test TEST_FILE=tests/tom_exec_test10.c
/// ```
int main(int argc, char *argv[], char *envp[])
{
	test00(argc, argv ,envp);
	return (0);
}
