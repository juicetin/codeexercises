#include <iostream>

using namespace std;

void foo (const int &number)
{
	cout << "const int& foo was called!" << endl;
}

void foo (int &number)
{
	number = 3;
	cout << "int& foo was called!" << endl;
}

int main()
{
	int localNumber = 1;
	cout << "localNumber = " << localNumber << endl;
	foo(localNumber);
	cout << "foo(localNumber); localNumber = " << localNumber << endl;

	const int constLocalNumber = 2;
	foo(constLocalNumber);

	int& numberRef = localNumber;
	cout << "&numberRef = " << &numberRef << endl;
	numberRef++;
	cout << "After numberRef++, &numberRef = " << &numberRef << endl;

	int *numberPtr = &localNumber;
	cout << "*numberPtr = " << *numberPtr << endl;
	numberPtr++;
	cout << "*numberPtr = " << *numberPtr << endl;
	cout << "numberRef = " << numberRef << endl;
	localNumber--;
	cout << "After decrementing localNumber, here's numberRef: " << numberRef << endl;
}
