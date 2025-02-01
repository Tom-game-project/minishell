#include "list.h"
#include <stdlib.h>


int main ()
{
	t_char_list *a;
	
	a = NULL;
	char_list_push(&a, 'b');
	char_list_push(&a, 'a');
	char_list_push(&a, 'n');
	char_list_push(&a, 'a');
	char_list_push(&a, 'n');
	char_list_push(&a, 'a');
	char_list_print(a);
	return (0);
}
