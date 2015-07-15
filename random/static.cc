#include <iostream>

int &foo ()
{
	static int a = 5;
	return a;
}

int main()
{
	int a = foo();
	int b = 10; 
	int c = 20;
	std::cout << a << std::endl;
}
