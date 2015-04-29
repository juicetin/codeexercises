#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long long toys, money; 
	cin >> toys >> money;
	long long prices[toys];
	for (long long i = 0; i < toys; ++i)
		cin >> prices[i];

	long long cumulative_cost = 0;
	long long bought_count = 0;
	sort(prices, prices+toys);
	
	for (long long i = 0; i < toys; ++i)
	{
		if (cumulative_cost + prices[i] <= money)
		{
			cumulative_cost += prices[i];
			bought_count++;
		}
	}

	cout << bought_count << endl;

	return 0;
}