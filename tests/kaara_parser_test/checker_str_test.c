#include "parser.h"
#include "stdio.h"
#include "libft.h"

int main(void)
{
    // printf("%d\n", str_ctl_len("\"hello ||\" && world"));
    // printf("%d\n", str_rdt_len("hello > world"));
    char *str = ft_strdup("echo && ((ehllo >> infile) >> outfile) || $(hello | echo)");
    if (checker_str_rdt(str))
        printf("true\n");
    free(str);
}