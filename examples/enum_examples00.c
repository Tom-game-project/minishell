#include <stdio.h>

typedef enum fruit t_fruit;
enum fruit
{
	apple, // #0
	orange, // #1
	grape   // #2
};

int main()
{
	t_fruit f = apple;

	if (f == apple)
	{
	}
	printf("fruit %d\n", f);
}
