#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
	int integer_count;
	cin >> integer_count;

	long long integers[integer_count];
	for (int i = 0;  i < integer_count; ++i)
		cin >> integers[i];

	long long p, q;
	cin >> p >> q;

	int max_index;
	long long max_value = LLONG_MIN;
	for (long long i = p; i <= q; ++i)
	{
		long long min = LLONG_MAX;
		for (int j = 0; j < integer_count; ++j)
		{
			long long temp = abs(integers[j] - i);
			if (temp < min)
				min = temp;
			// else if (temp <= max_value)
			// 	continue;
		}

		if (min > max_value)
		{
			max_value = min;
			max_index = i;
		}
	}

	return 0;
}