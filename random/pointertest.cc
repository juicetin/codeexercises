#include <iostream>

int main()
{
	int *a = new int(5);
	int *b = a;
	b = new int(1);
	std::cout << *a;	
}
