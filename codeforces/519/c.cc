#include <iostream>
using namespace std;
int main()
{
	long m, n;
	cin >> m >> n;
	long teams = 0;
	while((m >= 1 && n >= 2) || (m >= 2 && n >= 1))
	{
		if (m > n) {m-=2; n--;}
		else {m--; n-=2;}
		teams++;
	}
	cout << teams << endl;
}