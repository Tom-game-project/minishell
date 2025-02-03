#include "parser.h"

t_ast   *parser(char *input)
{
	t_ast		*ast;

    ast = allocation_ast();
	ast = parse_recursive(ast, search_operater(&input), &input);
	return (ast);
}

t_ast   *parse_recursive(t_ast *ast, char *element, char    **input)
{
	char	*element;

	if (input == NULL)
		return ;
	if (is_string(element) == false && is_control_operators(element) == true)//右の再起に潜る
		store_control_operators(ast, element, &input);
	if (is_string(element) == false && is_parce_control_operators(element) == true)
		store_redirection_operators(ast, element &input);
	else
		store_cmd_args(ast, element &input);
	ast->left = allocation_ast();
	parse_recursive(ast->left, element, &input);//基本は左に潜る潜る
	//
	//実行処理のプロセスでこの位置(waitpidのあと、右の再起に潜る前)、
	//elementをinputとして*parse_recursiveを渡したら展開もできる。はず。
	//forkはする。
	// if ([$()の判別式] == true);
	// 	実行部分大元の再起(parser(element));
	//
	return ;
}
