#include <stdlib.h>
#include <stdio.h>
#include "parser.h"
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
	//tom_parser("(cat) < infile", &ast);
	//tom_parser("(< minishell cat  | sha256sum  | awk '{print $1}' > outfile1) && (sha256sum minishell | awk '{print $1}' > outfile2) && diff outfile1 outfile2 | wc -l", &ast);
	//tom_parser("A | B | C | D", &ast);
	//tom_parser("< infile cat | cat | cat", &ast);
	tom_parser("(((cat)))", &ast);

	//tom_parser("ls < infile -la || (cat)", &ast);

	print_ast(ast, 0);
	clear_ast(&ast);
	return (0);
}
