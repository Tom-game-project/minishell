#include "parser.h"
#include <stdbool.h>
#include <stdio.h>

int main(void)
{
	bool    i;

	i = is_control_operators("hello world");
	if (i == false)
		printf("is_control : false\n");
	if (i == true)
		printf("is_control : true\n");

	i = is_control_operators("|| world");
	if (i == false)
		printf("is_control : || world :false\n");
	if (i == true)
		printf("is_control : || world :true\n");

	i = is_control_operators("&& world");
	if (i == false)
		printf("is_control : && world :false\n");
	if (i == true)
		printf("is_control : && world : true\n");
// //---------------------------------------------
   
	i = is_redirect_operators("hello world");
	if (i == false)
		printf("is_redirect : false\n");
	if (i == true)
		printf("is_redirect : true\n");

	i = is_redirect_operators("<< world");
	if (i == false)
		printf("is_redirect : << world :false\n");
	if (i == true)
		printf("is_redirect : << world :true\n");

	i = is_redirect_operators(">> world");
	if (i == false)
		printf("is_redirect : >> world :false\n");
	if (i == true)
		printf("is_redirect : >> world :true\n");

	i = is_redirect_operators("< world");
	if (i == false)
		printf("is_redirect : < world :false\n");
	if (i == true)
		printf("is_redirect : < world :true\n");

// //------------------------------------------------

    i = is_string("'hello world'");
    if (i == false)
        printf("is_string : 'hello world' : false\n");
    else if (i == true)
        printf("is_string : 'hello world' : true\n");
    i = is_string("'hello world");
    if (i == false)
		printf("is_string : 'hello world : false\n");
    else if (i == true)
		printf("is_string : 'hello world : true\n");
    i = is_string("(hello world)");
    if (i == false)
        printf("is_string : (hello world) : false\n");
    else if (i == true)
        printf("is_string : (hello world) : true\n");

    return (0);
}
