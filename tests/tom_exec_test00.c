#include "list.h"
#include "parser.h"
#include "exec.h"
#include <stdio.h>

/// exec2 のテスト
///
/// ```bash
/// make test TEST_FILE=tests/tom_exec_test00.c
/// ```
///
/// ```bash
/// ls -la | grep src
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

	//l0 = NULL;
	//str_list_push(&l0, "ls");
	//str_list_push(&l0, "-la");

	//l1 = NULL;
	//str_list_push(&l1, "cat");
	//str_list_push(&l1, "src");

	//l0 = NULL;
	//str_list_push(&l0, "cat");
	//str_list_push(&l0, "infile");

	//l1 = NULL;
	//str_list_push(&l1, "cat");

	//l0 = NULL;
	//str_list_push(&l0, "echo");
	//str_list_push(&l0, "infile");
        //
	//l1 = NULL;
	//str_list_push(&l1, "ls");
	//str_list_push(&l1, "-la");

	l0 = NULL;
	str_list_push(&l0, "grep");
	str_list_push(&l0, ".c");

	l1 = NULL;
	str_list_push(&l1, "ls");
	str_list_push(&l1, "-la");



	//str_list_push(&l1, );

	ast = &(t_ast) {
		&(t_ast) {
			NULL,
			NULL,
			e_ope_none,
			l0 // ls -la
		},
		&(t_ast) 
		{
			NULL,
			NULL,
			e_ope_none,
			l1 // grep src
		},
		e_ope_pipe,
		NULL,
	};
	d = NULL;
	envp_to_str_dict(&d, envp);
	exit_status = exec(ast, d);
	printf("exit status (%d)\n", exit_status);
	return (0);
}


/// ```bash
/// make test TEST_FILE=tests/tom_exec_test00.c
/// ```
int main(int argc, char *argv[], char *envp[])
{
	test00(argc, argv ,envp);
	return (0);
}

