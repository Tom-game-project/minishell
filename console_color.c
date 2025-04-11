#include <stdio.h>


int main()
{
	for (int i = 0; i < 16 * 3; i++) {
	  for (int j = 0; j < 32 * 3; j++) {
	    printf("\033[38;2;%d;%d;255mX", (i / 3)<<4, (j / 3)<<3);
	  }
	  printf("\033[0m\n");
	}
}

