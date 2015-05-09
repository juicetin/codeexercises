#include <iostream>
using namespace std;

int main()
{
	int error_count;
	cin >> error_count;

	long long first = 0;
	long long curr_err;
	for (int i = 0; i < error_count; ++i)
	{
		cin >> curr_err;
		first += curr_err;
	}

	long long second = 0;
	for (int i = 0; i < error_count-1; ++i)
	{
		cin >> curr_err;
		second += curr_err;
	}

	long long third = 0;
	for (int i = 0; i < error_count-2; ++i)
	{
		cin >> curr_err;
		third += curr_err;
	}

	cout << first - second << endl;
	cout << second - third << endl;
}