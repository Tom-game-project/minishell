#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define FILENAMEBUF 512

int usage()
{
	printf("引数を正しく入力してください\n");
	return (0);
}

/// chdirがどのように挙動するかのテスト
int main(int argc, char *argv[])
{
	int exit_status;
	char filepath[FILENAMEBUF];

	exit_status = 0;
	memset(filepath, '\0', FILENAMEBUF);
	if (argc == 2){
		if (chdir(argv[1]) == -1)
			exit_status = 1;
		getcwd(filepath, FILENAMEBUF);
		perror("example");
		printf("pwd %s\n", filepath);
	}
	else
		usage();
	return (exit_status);	
}
