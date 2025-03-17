#include <stdlib.h>
#include "tom_parser.h"
#include "test_tools.h"


/// ```bash
/// make test TEST_FILE=tests/tom_parser_test/tom_parser_test01.c
/// ```
int main()
{
	t_ast *ast;

	//ast = init_ast();
	//lexed = lexer("a || b");
	//lexed = lexer("ls < infile -la || cat");
	//tom_parser_lexed(&ast, lexed);
	ast = NULL;
	//tom_parser("ls < infile -la || cat", &ast);
	//tom_parser("(ls < infile -la) || (cat)", &ast);
	tom_parser("(cat) < infile", &ast);
	//tom_parser("ls < infile -la || (cat)", &ast);
	
	print_ast(ast, 0);
	return (0);
}
