#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
double fib_map[5000];

double fib_rec(double n);
double fib_iter(double n);
double fib_dp(int n);

int main(int argc, char **argv)
{
	memset(fib_map, 0, sizeof(fib_map));
	fib_map[1] = 1;
	fib_map[2] = 1;

	// double num;
	// cin >> num;
	cout << "The " << argv[1] << "th fib_reconacci number is " << fib_iter(atoi(argv[1])) << endl;
}

//45th - 35 seconds
double fib_rec(double n)
{
	if (n <= 0) return -1;
	else if (n == 1) return 1;
	else if (n == 2) return 1; 
	return fib_rec(n-1) + fib_rec(n-2);
}

double fib_dp(int n)
{
	if (fib_map[n] != 0)
	{
		return fib_map[n];
	}
	
	if (fib_map[n-2] == 0)
	{
		fib_dp(n-2);
	}

	if (fib_map[n-1] == 0)
	{
		fib_dp(n-1);
	}

	fib_map[n] = fib_map[n-1] + fib_map[n-2];

	return fib_map[n];
}

//45th - 0 seconds
double fib_iter(double n)
{
	double index = 0, cur = 0, prev = 1;
	while (index < n)
	{
		double tmp = cur;
		cur += prev;
		prev = tmp;
		index++;
	}
	return cur;
}

