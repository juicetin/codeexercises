#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

#define LENGTH 0
#define ONES 1
#define FIB 2

typedef vector<vector<int>> myData;

int fibonacci(int cap, vector<vector<int> > * data)
{
	int index = 0, cur = 0, prev = 1, cumul = 0;
	while(cumul <= cap)
	{
		int tmp = cur;
		cur += prev;
		prev = tmp;
		index++;
		cumul += index * cur;

		vector<int> tmp_v;
		tmp_v.push_back(index);
		tmp_v.push_back(0);
		tmp_v.push_back(cur);
		(*data).push_back(tmp_v);
	}
	return index - 1;
}

int main()
{
	vector<vector<int> > data;
	// int length;
	// cin >> length;

	// while(joined_string.size() < length)
	// {
	// 	//Append next "binary fibonacci" to int vector
	// }

	cout << fibonacci(9, &data) << endl;
}
