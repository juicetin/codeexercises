#include <iostream>
using namespace std;
static const int b = 73;

const int& foo()
{
//	int * b = new int(5);
//	int &a = *b;
//	return a;
	int a = 10;
	return a;
}

const int& fizz()
{
	return b;
}

int main()
{
	//const int &b = foo();
	

	const int& a = fizz(); 
	cout << a << endl;

	return 0;
}
