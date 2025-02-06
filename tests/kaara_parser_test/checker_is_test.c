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

//----------------------------------------

	i = ft_isspace(' ');
	if (i == false)
		printf("isspace : false\n");
	else if (i == true)
		printf("isspace : true\n");

	i = ft_isspace('\t');
	if (i == false)
		printf("isspace : false\n");
	else if (i == true)
		printf("isspace : true\n");

	i = ft_isspace('\n');
	if (i == false)
		printf("isspace : false\n");
	else if (i == true)
		printf("isspace : true\n");

	i = ft_isspace('a');
	if (i == false)
		printf("isspace : false\n");
	else if (i == true)
		printf("isspace : true\n");

//-------------------------------------------------

	printf("\nchecker_str_ctl\n");

	i = checker_str_ctl("");
	if (i == false)
		printf(" : false\n");
	else if (i == true)
		printf(" : true\n");

	i = checker_str_ctl("hello");
	if (i == false)
		printf("hello : false\n");
	else if (i == true)
		printf("hello : true\n");

	i = checker_str_ctl("\"he||llo&&\"");
	if (i == false)
		printf("\"he||llo&&\" : false\n");
	else if (i == true)
		printf("\"he||llo&&\" : true\n");

	i = checker_str_ctl("\"he||llo&&\" && hello");
	if (i == false)
		printf("\"he||llo&&\" && hello : false\n");
	else if (i == true)
		printf("\"he||llo&&\" && hello : true\n");

//--------------------------------------------------------

	printf("\nchecker_str_rdt\n");
	i = checker_str_rdt("");
	if (i == false)
		printf(" : false\n");
	else if (i == true)
		printf(" : true\n");

	i = checker_str_rdt("hello");
	if (i == false)
		printf("hello : false\n");
	else if (i == true)
		printf("hello : true\n");

	i = checker_str_rdt("\"he<llo&&\"");
	if (i == false)
		printf("\"he<llo&&\" : false\n");
	else if (i == true)
		printf("\"he<llo&&\" : true\n");

	i = checker_str_rdt("\">>he>>llo>>\" | hello");
	if (i == false)
		printf("\">he>>llo>>\" | hello : false\n");
	else if (i == true)
		printf("\">he>>llo>>\" | hello : true\n");
	return (0);
}

