# include "parser.h"
# include "libft.h"
# include <stdlib.h>

void	update_input(char **input, char *head_element)
{
	int i;
	char *tmp;

	i = 1;
	if (ft_strncmp(head_element, "&&", ft_strlen(head_element)) == 0
		|| ft_strncmp(head_element, "||", ft_strlen(head_element)) == 0)
		i = 2;
	if (*input[0] == '\'' || *input[0] == '"')
		i = find_chr(*input + 1, '\'') + 1;
	tmp = ft_substr(*input, i, ft_strlen(*input + i));
	free(*input);
	*input = tmp;
}
