# include "parser.h"

t_ast   *parser(char *input)
{
    t_ast   *ast;

    ast = NULL;
    ast = parse_recursive(ast, input);
    return (ast);
}

t_ast  *parse_recursive(t_ast *ast, char *input)
{   
    if (input == NULL)
    {
        ast = NULL;
        return (ast);
    }
    ast = allocation_ast();
    check_operator(ast, input);
    parse_recursive(ast, input);
    return (ast);
}

t_ast  *allocation_ast(void)
{
    t_ast *ast;

    ast = (t_ast *)malloc(sizeof(t_ast));
    if (ast == NULL)
        exit(1);
    return (ast);
}

    
void    check_operator(t_ast *ast, char *input)
{
    if (ft_strnstr(input, "&&", ft_strlen(input))
        || ft_strnstr(input, "||", ft_strlen(input)))
    {
        if (ft_strnstr(input, "&&", ft_strlen(input))
        < ft_strnstr(input, "||", ft_strlen(input)))
            (input, "&&");
        else
            (input, "||");
    }

}