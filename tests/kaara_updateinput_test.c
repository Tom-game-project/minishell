#include "parser.h"
#include "libft.h"
#include <stdio.h>
 
int main(void)
{
    char *input;
    char *head_element;

    input = ft_strdup("&& ls -la");
    head_element = ft_strdup("&&");
    update_input(&input, head_element);
    printf("%s\n", input);
    free(head_element);

    head_element = ft_strdup(" ");
    update_input(&input, head_element);

    printf("%s\n", input);
    free(input);
    free(head_element);
    return (0);
}

//void	update_input(char **input, char *head_element);
//inputの先頭にある区切り文字を切り取ってinput次の要素が先頭に来るように更新する。
//想定される区切り文字は',",(,),&&,||,|,spcの8つ。