#include <linux/limits.h>
#include <unistd.h>
#include <limits.h>

// for test 
#include <stdio.h>

/// 現在いるディレクトリを返却する
int main()
{
	char str[PATH_MAX];

	getcwd(str, PATH_MAX);
	printf("[%s] \n", str);
	return(0);
}
