///

#include "tom_parser_tools/tools.h"
#include <stdio.h>

/// astを表示する機能のテスト
/// ```bash
/// make test TEST_FILE=tests/tom_parser_tools_test.c
/// ```
int main()
{
	t_ast *ast;

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

	print_ast(ast, 0);
	printf("\n");
	return (0);
}
