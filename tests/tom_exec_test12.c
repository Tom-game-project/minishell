#include "list.h"
#include "parser.h"
#include "exec.h"
#include <stdio.h>


/// exec2 のテスト
///
/// `>`の処理のテスト
///
/// ```bash
/// make test TEST_FILE=tests/tom_exec_test12.c
/// ```
///
/// ```bash
/// echo hello world > outfile
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
	str_list_push(&l0, "echo");
	str_list_push(&l0, "hello");
	str_list_push(&l0, "world");
	str_list_push(&l0, "this");
	str_list_push(&l0, "is");
	str_list_push(&l0, "Tom!");


	l1 = NULL;
	str_list_push(&l1, "outfile");

	ast = &(t_ast) {
		&(t_ast) {
			NULL,
			NULL,
			e_ope_none,
			l0 // echo hello world
		},
		NULL,
		e_ope_redirect_o, // `>`
		l1, // outfile
	};
	d = NULL;
	envp_to_str_dict(&d, envp);
	exit_status = exec(ast, d, STDIN_FILENO);
	printf("exit status (%d)\n", exit_status);
	return (exit_status);
}


/// exec2 のテスト
///
/// `>`の処理のテスト
///
/// ```bash
/// make vtest TEST_FILE=tests/tom_exec_test12.c
/// ```
///
/// ```bash
/// > outfile echo hello
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
	str_list_push(&l0, "echo");
	str_list_push(&l0, "hello");
	str_list_push(&l0, "world");
	str_list_push(&l0, "this");
	str_list_push(&l0, "is");
	str_list_push(&l0, "Tom!");

	l1 = NULL;
	str_list_push(&l1, "outfile");

	ast = &(t_ast) {
		NULL,
		&(t_ast) {
			NULL,
			NULL,
			e_ope_none,
			l0, // echo hello
		},
		e_ope_redirect_o, // `>`
		l1, // outfile
	};
	d = NULL;
	envp_to_str_dict(&d, envp);
	exit_status = exec(ast, d, STDIN_FILENO);
	printf("exit status (%d)\n", exit_status);
	return (exit_status);
}


/// ```bash
/// make test TEST_FILE=tests/tom_exec_test12.c
/// ```
int main(int argc, char *argv[], char *envp[])
{
	test00(argc, argv ,envp);
	return (0);
}
