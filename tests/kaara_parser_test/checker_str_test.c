#include "parser.h"
#include "stdio.h"

int main(void)
{
    printf("%d\n", str_ctl_len("\"hello ||\" && world"));
    printf("%d\n", str_rdt_len("hello > world"));
}