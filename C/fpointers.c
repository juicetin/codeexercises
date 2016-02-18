#include <stdio.h>

int add_int(int n, int m)
{
	return n+m;
}

typedef int (*myFuncDef)(int, int);

int (*function_ptr)(int, int);

int add2to3(int (*function_ptr)(int, int))
{
	return (*function_ptr)(2, 3);
}

// This is a function which receives parameter n and returns 
// a pointer to another function which receives to ints and it
// returns another int
//int (*functionFactory (int n)) (int, int)
myFuncDef functionFactory (int n)
{
	printf("Got parameter %d", n);
	int (*function_ptr)(int, int) = &add_int;
	return function_ptr;
}

int main(void)
{
	function_ptr = &add_int;
	int sum = (*function_ptr)(2, 3);
	printf("%d\n", sum);
}
