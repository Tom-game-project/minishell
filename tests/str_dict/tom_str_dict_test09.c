#include "dict.h"
#include <stdlib.h>


int main(int argc, char *argv[], char *envp[])
{
	(void) argc;
	(void) argv;

	t_str_dict *d;
	d = NULL;
	envp_to_str_dict(&d, envp);
	str_dict_print(d);
	str_dict_clear(&d, free, free);
	return (0);

}
