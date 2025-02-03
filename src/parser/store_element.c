#include "parser.h"
#inlcude "libft.h"

void	store_control_operators(t_ast *ast, char *element, char    **input)
{
	//格納処理
	//右への再起処理
	ast->right = allocation_ast();
	parse_recursive(ast->right, search_operater(&input), &input);
	return ;
}

void	store_redirection_operators(t_ast *ast, char *element, char    **input)
{
	//格納処理
}

void	store_cmd_args(t_ast *ast, char *element, char    **input)
{

}