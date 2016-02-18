#include <stdio.h>

int function (int foo)
{
	
}

int main(void)
{
	int count = 7;
	int * countp = &count;
	printf("%d %d\n", countp, &count);
	printf("%d\n", *countp);

	return 0;
}
