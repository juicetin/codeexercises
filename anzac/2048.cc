#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	int lines;
	cin >> lines;
	for (int i = 0; i < lines; ++i)
	{
		unsigned long long x, y;
		cin >> x >> y;
		cout << fixed << setprecision(0) << y * ((log(y)/log(x))-1) << endl;	
	}
}
