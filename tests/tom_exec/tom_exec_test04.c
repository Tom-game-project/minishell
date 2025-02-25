#include "dict.h"
#include "list.h"
#include "parser.h"
#include "exec.h"
#include <stdio.h>
#include <stdlib.h>


void nop(void *a)
{
	(void) a;
}


/// exec2 のテスト
///<stdio.h>
/// ```bash
/// make test TEST_FILE=tests/tom_exec_test04.c
/// ```
///
/// ```bash
/// ls -la | cat | grep src
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
	t_str_list *l2;

	l0 = NULL;
	str_list_push(&l0, "ls");
	str_list_push(&l0, "-la");

	l1 = NULL;
	str_list_push(&l1, "cat");
	// str_list_push(&l1, "-la");

	l2 = NULL;
	str_list_push(&l2, "grep");
	str_list_push(&l2, "src");
	//str_list_push(&l1, "world");

	//str_list_push(&l2, "echo");
	//str_list_push(&l2, "$(ls -la)");

	// test case: echo hello | cat

	ast = &(t_ast) {
		&(t_ast) {
			NULL,
			NULL,
			e_ope_none,
			l0 // ls -la
		},
		&(t_ast) 
		{
			&(t_ast) {
				NULL,
				NULL,
				e_ope_none,
				l1 // cat
			},
			&(t_ast) 
			{
				NULL,
				NULL,
				e_ope_none,
				l2 // grep src
			},
			e_ope_pipe,
			NULL,
		},
		e_ope_pipe ,
		NULL,
	};
	d = NULL;
	envp_to_str_dict(&d, envp);
	exit_status = exec(ast, &d);
	printf("exit status (%d)\n", exit_status);

	/// リソースの解放
	str_list_clear(&l0, nop);
	str_list_clear(&l1, nop);
	str_list_clear(&l2, nop);
	str_dict_clear(&d, free, free);
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
