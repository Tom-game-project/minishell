#include "parser.h"
#include "libft.h"

t_ast   *parser(char *input)
{
	t_ast		*ast;

    ast = allocation_ast();
	ast = separate_and_store_control_operators(ast, &input);
	if (ast != NULL)
		return (ast);
	ast = separate_and_store_store_redirection_operators(ast, &input);
	if (ast != NULL)
		return (ast);
	ast = separate_and_store_cmd_args(ast, &input);
	if (ast != NULL)
		return (ast);
	return (NULL);
}

	//
	//実行処理のプロセスでこの位置(waitpidのあと、右の再起に潜る前)、
	//elementをinputとして*parse_recursiveを渡したら展開もできる。はず。
	//forkはする。
	// if ([$()の判別式] == true);
	// 	実行部分大元の再起(parser(element));
	//