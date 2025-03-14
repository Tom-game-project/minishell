
#include "dict.h"
#include "list.h"
#include "parser.h"
#include "exec.h"
#include "libft.h"
#include <stdio.h>

/// exec2 のテスト
///
/// `&&`と同じように挙動するかどうかを確かめる
///
/// ```bash
/// make test TEST_FILE=tests/tom_exec_test05.c
/// ```
///
/// ```bash
/// true && echo world success!
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
	str_list_push(&l0, ft_strdup("ls"));
	str_list_push(&l0, ft_strdup("-la"));

	l1 = NULL;
	str_list_push(&l1, ft_strdup("grep"));
	str_list_push(&l1, ft_strdup("src"));

	ast = &(t_ast) {
		&(t_ast) {
			&(t_ast) {
				NULL,
				NULL,
				e_ope_none,
				l0 // `ls -la`
			},
			NULL,
			e_ope_paren,
			NULL
		},
		&(t_ast) 
		{
			&(t_ast) {
				NULL,
				NULL,
				e_ope_none,
				l1 // `grep src`
			},
			NULL,
			e_ope_paren,
			NULL
		},
		e_ope_pipe, // `|`
		NULL,
	};
	d = NULL;
	envp_to_str_dict(&d, envp);
	exit_status = exec(ast, &d);
	printf("exit status (%d)\n", exit_status);
	str_dict_clear(&d, free, free);
	str_list_clear(&l0, free);
	str_list_clear(&l1, free);
	return (exit_status);
}


/// ```bash
/// make test TEST_FILE=tests/tom_exec/tom_exec_test15.c
/// ```
int main(int argc, char *argv[], char *envp[])
{
	test00(argc, argv ,envp);
	return (0);
}
