#include <stdio.h>

int g_this_is_global = 0;

int func()
{
	printf("[%d]\n", g_this_is_global);
	return (0);
}

/// 
/// ```bash
/// make example EXAMPLE_FILE=examples/global_valiable.c
/// ```
int main()
{
	func();
	g_this_is_global = 1;
	func();
	return (0);
}
