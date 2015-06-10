#include <iostream>
using namespace std;

int main()
{
	int x = 5;
	const int &z = x;
	int &w = x;
	int *xPtr = &x;

	cout << "xPtr " << *xPtr << endl;
	xPtr++;
	w++;
	cout << "xPtr " << *xPtr << endl;
	cout << w << " " << x << endl;
}
