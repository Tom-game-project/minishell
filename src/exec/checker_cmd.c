
# include "parser.h"
 
bool	checker_cmd(t_ast *ast)
{
    t_ast	*head;
 
    while (ast)
    {
	    if (checker_str_ctl(ast))
    		return (false);

    }
    if (ast)
    	

	return (true);
}