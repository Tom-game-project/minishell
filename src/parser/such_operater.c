#include "parser.h"
#include "string.h"

char *surch_operater(char **input)
{
	char    *head_element;

	if (*input[0] == "'")
		head_element = ft_substr(*input, 0, strchar(input[i], "'"));
	else if (*input[0] == "'")
		head_element = ft_substr(*input, 0, strchar(input[i], '"'));
	else if (*input[0] == "(")
		head_element = ft_strdup("(");
	else if (*input[0] == ")")
		head_element = ft_strdup(")");
	else if (*input[0] == "&" && *input[1] == "&")
		head_element = ft_strdup("&&");
	else if (*input[0] == "|" && *input[1] == "|")
		head_element = ft_strdup("||");
	else if (*input[0] == "|")
		head_element = ft_strdup("|");
	else if (*input[0] == " ")
		head_element = ft_strdup(" ");
	else
		head_element = NULL;
	if (head_element != NULL)
		update_input(input);
	return (head_element);
}