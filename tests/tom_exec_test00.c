#include "list.h"
#include "parser.h"
#include <stdlib.h>

int test00()
{
	t_ast *ast;

	t_str_list *l0;
	t_str_list *l1;
	t_str_list *l2;

	l0 = NULL;
	str_list_push(&l0, "echo");
	str_list_push(&l0, "hello");

	l1 = NULL;
	str_list_push(&l1, "cat");

	l2 = NULL;
	str_list_push(&l2, "ls");
	str_list_push(&l2, "-la");


	//str_list_push(&l2, "echo");
	//str_list_push(&l2, "$(ls -la)");

	// echo hello | (cat | ls -la)
	//
	// < outfile cat ls 

	ast = &(t_ast) {
		&(t_ast) {
			NULL,
			NULL,
			e_rdtope_none,
			NULL,
			l0 // echo hello
		},
		&(t_ast) {
			&(t_ast) 
			{
				NULL,
				NULL,
				e_rdtope_none,
				NULL,
				l1 // cat
			},
			&(t_ast) {
				NULL,
				NULL,
				e_rdtope_none,
				NULL,
				l2 // ls -la
			},
			e_rdtope_pipe,
			NULL,
			NULL

		},
		e_rdtope_pipe ,
		NULL,
		NULL
	};

	return (0);
}

/// ```bash
/// make test TEST_FILE=tests/tom_exec_test00.c
/// ```
int main()
{
	return (0);
}
