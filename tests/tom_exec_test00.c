#include "list.h"
#include "parser.h"
#include "exec.h"
#include <stdio.h>

//int test00()
//{
//	t_ast *ast;
//
//	t_str_list *l0;
//	t_str_list *l1;
//	t_str_list *l2;
//
//	l0 = NULL;
//	str_list_push(&l0, "echo");
//	str_list_push(&l0, "hello");
//
//	l1 = NULL;
//	str_list_push(&l1, "cat");
//
//	l2 = NULL;
//	str_list_push(&l2, "ls");
//	str_list_push(&l2, "-la");
//
//
//	//str_list_push(&l2, "echo");
//	//str_list_push(&l2, "$(ls -la)");
//
//	// echo hello | cat | ls -la
//	//
//	// < outfile cat ls 
//
//	ast = &(t_ast) {
//		&(t_ast) {
//			NULL,
//			NULL,
//			e_ope_none,
//			NULL,
//			l0 // echo hello
//		},
//		&(t_ast) {
//			&(t_ast) 
//			{
//				NULL,
//				NULL,
//				e_ope_none,
//				NULL,
//				l1 // cat
//			},
//			&(t_ast) {
//				NULL,
//				NULL,
//				e_ope_none,
//				NULL,
//				l2 // ls -la
//			},
//			e_ope_pipe,
//			NULL,
//			NULL
//		},
//		e_ope_pipe ,
//		NULL,
//		NULL
//	};
//
//	return (0);
//}

int test01(int argc, char *argv[], char *envp[])
{
	(void) argc;
	(void) argv;

	t_ast *ast;
	t_str_dict *d;

	t_str_list *l0;
	t_str_list *l1;

	l0 = NULL;
	str_list_push(&l0, "echo");
	str_list_push(&l0, "hello");

	l1 = NULL;
	str_list_push(&l1, "grep");
	str_list_push(&l1, "hello");
	//str_list_push(&l1, "world");

	//str_list_push(&l2, "echo");
	//str_list_push(&l2, "$(ls -la)");

	// test case: echo hello | cat

	ast = &(t_ast) {
		&(t_ast) {
			NULL,
			NULL,
			e_ope_none,
			NULL,
			l0 // echo hello
		},
		&(t_ast) 
		{
			NULL,
			NULL,
			e_ope_none,
			NULL,
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


int test02(int argc, char *argv[], char *envp[])
{
	(void) argc;
	(void) argv;

	t_ast *ast;
	t_str_dict *d;

	t_str_list *l0;
	t_str_list *l1;

	l0 = NULL;
	str_list_push(&l0, "echo");
	str_list_push(&l0, "hello");

	l1 = NULL;
	str_list_push(&l1, "echo");
	str_list_push(&l1, "world");

	//str_list_push(&l2, "echo");
	//str_list_push(&l2, "$(ls -la)");

	// test case: echo hello | cat

	ast = &(t_ast) {
		NULL,
		NULL,
		e_ope_none,
		NULL,
		l0 // echo hello
	};
	d = NULL;
	envp_to_str_dict(&d, envp);
	exec2(ast, d, STDIN_FILENO, -1);
	return (0);

}


/// ```bash
/// make test TEST_FILE=tests/tom_exec_test00.c
/// ```
int main(int argc, char *argv[], char *envp[])
{
	test01(argc, argv ,envp);
	return (0);
}
