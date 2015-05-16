#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int maxSubArray(vector<int> v)
{
	int max_ending_here, max_so_far;
	max_ending_here = max_so_far = v[0];
	for (int i = 1; i < v.size(); ++i)
	{
		max_ending_here = max(v[i], max_ending_here + v[i]);
		max_so_far = max(max_so_far, max_ending_here);
	}

	return max_so_far;
}

int main() {
	int cases;
	cin >> cases;

	//Cases
	for (int i = 0; i < cases; ++i)
	{
		int items;
		cin >> items;
		if (items <= 0)
		{
			cout << "0 0" << endl; 
			continue;
		}

		//Store test case
		vector<int> _array;
		int item;
		for (int j = 0; j < items; ++j)
		{
			cin >> item;
			_array.push_back(item);
		}

		//Operate on test case
		int c_sum = 0, nc_sum = 0, largest = INT_MIN, add_cnt = 0;
		for (int i : _array)
		{
			//Non-contigious max subarray
			if (i > 0)
			{
				nc_sum += i;
				add_cnt = 0;
			}
			if (i > largest)
			{
				largest = i;
			}
		}
		if (add_cnt == 0)
		{
			nc_sum = largest;
		}

		//Contigious max subarray
		c_sum = maxSubArray(_array);

		cout << c_sum << " " << nc_sum << endl;
	}
	return 0;
}
