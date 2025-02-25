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
	size_t	after_trim_len;
	char	*after_trim;

	if (head_element == NULL)
		return ;
	after_trim = trim_isspc(*input);
	after_trim_len = ft_strlen(after_trim);
	free(*input);
	*input = ft_substr(after_trim, ft_strlen(head_element), after_trim_len - ft_strlen(head_element));
	free(after_trim);
}
