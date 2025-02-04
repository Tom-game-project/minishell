
#include "parser.h"
#include "libft.h"
#include <stdlib.h>


t_ast   *separate_and_store_cmd_args(t_ast *ast, char **input)
{
    int     i;
    char    **cmd_and_argv;

    if (is_string(*input) == true)
        return (NULL);
    cmd_and_argv = ft_split(*input, ' ');
    if (cmd_and_argv == NULL)
        exit(EXIT_FAILURE);
    i = 0;
    while (cmd_and_argv[i] != NULL)
        i++;
    ast->argv = (char **)malloc(sizeof(char *) * i);
    if (ast->argv == NULL)
        exit(EXIT_FAILURE);
    ast->cmd = ft_strdup(cmd_and_argv[0]);
    free(cmd_and_argv[0]);
    i = 0;
    while (cmd_and_argv[i] != NULL)
    {
        ast->argv[i - 1] = ft_strdup(cmd_and_argv[i + 1]);
        free(cmd_and_argv[i]);
        i++;
    }
    ast->argv[i - 1] = NULL;
    free(cmd_and_argv);
    return (ast);
}
