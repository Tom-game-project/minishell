#include <stdio.h>

int main(int argc, char *argv[], char **envp)
{
	char **envp_p;
	int i;

	(void) argc;
	(void) argv;
	envp_p = envp;
	i = 0;
	while (*envp_p != NULL)
	{
		printf("[%d] %s\n", i, *envp_p);
		envp_p++;
		i += 1;
	}
	return (0);
}
