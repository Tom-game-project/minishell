
#include "parser.h"
#include "list.h"
#include "libft.h"
#include <stdlib.h>

#include <stdio.h>

int main(void)
{
    printf("%s\n", trim_isspc("hello\n\n"));
    printf("%s\n", trim_isspc("hello  "));
    printf("%s\n", trim_isspc("   hello"));
    printf("%s\n", trim_isspc("\n  hello \t"));
    printf("%s\n", trim_isspc(""));
    return (0);
}

