#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int items;
	cin >> items;

	vector<long> item_list;
	for (int i = 0; i < items; ++i)
	{
		long tmp;
		cin >> tmp;
		item_list.push_back(tmp);
	}

	sort(item_list.begin(), item_list.end());
	long cur_w = item_list[0] + 4;
	int buy_count = 1;
	for (int i = 0; i < items; ++i)
	{
		if (item_list[i] > cur_w)
		{
			cur_w = item_list[i] + 4;
			buy_count++;
		}
	}
	cout << buy_count << endl;
    return 0;
}
