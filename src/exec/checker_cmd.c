
# include "parser.h"
 
bool	checker_cmd(t_ast *ast)
{
    t_ast	*head;

    if (ast->cmd != NULL)
        return (false);
    while (ast)
    {
	    if (checker_str_ctl(ast))
    		return (false);

    }
    if (ast)
    	


	return (true);
}
