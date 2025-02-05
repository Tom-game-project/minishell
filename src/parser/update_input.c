# include "parser.h"
# include "libft.h"
# include <stdlib.h>
# include <stdio.h>

// void	update_input(char **input, char *head_element)
// {
// 	char	*tmp;

// 	if (ft_strncmp(*input, head_element, ft_strlen(*input)) == 0)
// 	{
// 		free(*input);
// 		*input = NULL;
// 		return ;
// 	}
// 	tmp = ft_substr(*input, ft_strlen(head_element), ft_strlen(*input) - ft_strlen(head_element));
// 	free(*input);
// 	*input = tmp;
// }

void	update_input(char **input, char *head_element)
{
	size_t	leading_spaces;
	size_t	start;
	size_t	input_len;
	char	*tmp;

	if (*input == NULL || head_element == NULL)
		return;
	leading_spaces = 0;
	while (*input[leading_spaces] != '\0' && ft_isspace(*input[leading_spaces]))
		leading_spaces++;
	start = ft_strlen(head_element) + leading_spaces;
	input_len = ft_strlen(*input);
	tmp = ft_substr(*input, start, input_len - start);
	free(*input);
	*input = tmp;
}
