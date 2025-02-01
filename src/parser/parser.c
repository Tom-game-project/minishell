# include "parser.h"

t_ast   *parser(char *input)
{
    t_ast   *ast;
    char    **tokens;

    ast = NULL;
    tokens = split_input(input);
    ast = parse_recursive(ast, tokens);
    return (ast);
}

t_ast  *parse_recursive(t_ast *ast, char *tokens)
{   

    if ()//検討中
    {
        ast = NULL;
        return (ast);
    }
    ast = allocation_ast();
    check_operator(ast, tokens);
    parse_recursive(ast, tokens);
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
    ""''

    //and or
    // if (ft_strnstr(input, "&&", ft_strlen(input))
    //     || ft_strnstr(input, "||", ft_strlen(input)))
    // {
    //     if (ft_strnstr(input, "&&", ft_strlen(input))
    //     < ft_strnstr(input, "||", ft_strlen(input)))
    //         (input, "&&");
    //     else
    //         (input, "||");
    // }
}

void    split_and_or(t_ast *ast, char *input)
{
    char    *left_line;
    char    *right_line;

    if (ft_strnstr(input, "&&", ft_strlen(input))
        || ft_strnstr(input, "||", ft_strlen(input)))
    {
        if (ft_strnstr(input, "&&", ft_strlen(input))
        < ft_strnstr(input, "||", ft_strlen(input)))
        {
            left_line = substr(input, (int)strcheck(input, '&'), );
            right_line = substr
        }
        else
            (input, "||");
    }
}