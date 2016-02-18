#include <stdio.h>

void get_and_put_char() 
{
	int a = getchar();
	printf("You just entered: ");
	putchar(a);
}

void read() {
	int x;
	float f;
	scanf("%d %f", &x, &f);
	printf("You entered int [%d] and float [%f]", x, f);
}

int main(void)
{
	// get_and_put_char();
	read();
}
