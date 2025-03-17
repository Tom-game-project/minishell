#include "list.h"
#include "tom_parser.h"

/// ```bash
/// make test TEST_FILE=tests/tom_parser_test/tom_parser_test01.c
/// ```
int main()
{
	t_tom_ast *ast;
	t_str_list *lexed;

	ast = init_ast();
	lexed = lexer("a || b");
	tom_parser_lexed(&ast, lexed);
	return (0);
}
