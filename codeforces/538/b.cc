#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	long num;
	cin >> num;

	long divider = 1;
	vector<long> store;
	long largest = 0;

	/*Run through the number and store its digits*/
	while (divider <= num)
	{
		store.push_back(num/divider % 10);
		if (num/divider % 10 > largest)
		{
			largest = num/divider % 10;
		}
		divider *= 10;
	}

	cout << largest << endl;
	for (int i = 0; i < largest; ++i)
	{
		string tmp;
		for (int j = store.size()-1; j != -1; --j)
		{
			if (store[j] > 0)
			{
				tmp.push_back('1');
				store[j]--;
			}
			else if (store[j] == 0)
			{
				tmp.push_back('0');
			}
		}

		/*Remove all leading zeroes then print*/
		tmp.erase(0, tmp.find_first_not_of('0'));
		cout << tmp << " ";
	}
	cout << endl;
}
