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
	size_t	tmp_len;
	char	*tmp;

	tmp = trim_isspc(*input);
	tmp_len = ft_strlen(tmp);
	free(*input);
	*input = ft_substr(tmp, ft_strlen(head_element), tmp_len - ft_strlen(head_element));
	free(tmp);
}
