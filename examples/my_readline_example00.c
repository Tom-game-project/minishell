/// もし、
/// ファイルを　STDINとして読み込みたい
///
///

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>


#define BUF_SIZE 1024

int main()
{
	//int fd;
	char buf[BUF_SIZE];


	//fd = open("./infile", O_RDONLY, 0644);
	//dup2(fd, STDIN_FILENO);

	if (isatty(STDIN_FILENO))
	{
		printf("ttyだよ\n");
	}
	else{
		// 非プロンプトモード
		printf("ttyじゃないよ\n");
		while(1)
		{

		}
		read(STDIN_FILENO, buf, BUF_SIZE);
	}
	printf("%s\n", buf);
	//close(fd);
	return (0);
}
