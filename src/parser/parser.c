#include "parser.h"
#include "libft.h"

t_ast   *parser(char *input)
{
	t_ast		*ast;

    ast = allocation_ast();
	ast = parse_recursive(ast, search_operater(&input), &input);
	return (ast);
}

t_ast   *parse_recursive(t_ast *ast, char    **input)
{
	if (input == NULL)
		return (ast);
	separate_and_store_control_operators(ast, input);
	separate_and_store_store_redirection_operators(ast, input);
	separate_and_store_cmd_args(ast, input);
	ast->right_ast = allocation_ast();
	parse_recursive(ast->right_ast, input);
	return (ast);
}

	//
	//実行処理のプロセスでこの位置(waitpidのあと、右の再起に潜る前)、
	//elementをinputとして*parse_recursiveを渡したら展開もできる。はず。
	//forkはする。
	// if ([$()の判別式] == true);
	// 	実行部分大元の再起(parser(element));
	//